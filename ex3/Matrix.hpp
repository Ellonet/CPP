//
// Created by אלה on 06/01/2019.
//
#ifndef EX3_MATRIX_HPP
#define EX3_MATRIX_HPP

#include <vector>
#include <iostream>
#include "Complex.h"

using namespace std;

class MyException : public std::exception
{
public:
    explicit MyException(const char *messege) : _message(messege)
    {}

    const char *what() const throw() override
    {
        return _message;
    }

private:
    const char *_message;
};


template<class T>
class Matrix
{
private:
    vector<T> _matrix;
    unsigned int _rowNum;
    unsigned int _colNum;

public:
    // --- constructors --- //
    Matrix() : _colNum(1), _rowNum(1)
    { _matrix.push_back(0); }

    Matrix(const unsigned int rows, const unsigned int cols) : _colNum(cols), _rowNum(rows),
                                                               _matrix(rows * cols, 0)
    {}

    Matrix(const Matrix &other) = default;

    Matrix(const unsigned int rows, const unsigned int cols, const vector<T> &cells) : _colNum(cols),
                                                                                       _rowNum(rows)
    {
        for (auto &i : cells)
        {
            _matrix.push_back(i);
        }
    }

    ~Matrix() = default;

    // --- operators --- //

    friend ostream &operator<<(ostream &out, const Matrix &mat)
    {
        int t = 0;
        for (int i = 0; i < mat._rowNum; ++i)
        {
            for (int j = 0; j < mat._colNum; ++j)
            {
                out << mat._matrix[t++] << "\t";
            }
            out << endl;
        }
        return out;
    }

    Matrix<T> &operator=(const Matrix<T> &other) = default;
    // TODO - handle memory exceptions!

    Matrix<T> operator+(const Matrix<T> &other) const
    {
        vector<T> res;
        if (other._colNum != _colNum || other._rowNum != _rowNum)
        {
            throw MyException("Error - Unmatching dimensions");
        }
        for (int i = 0; i < _rowNum * _colNum; ++i)
        {
            res.push_back(_matrix[i] + other._matrix[i]);
        }
        return Matrix(_rowNum, _colNum, res);
    }

    Matrix<T> operator-(const Matrix<T> &other) const
    {
        vector<T> res;
        if (other._colNum != _colNum || other._rowNum != _rowNum)
        {
            throw MyException("Error - Unmatching dimensions");
        }
        for (int i = 0; i < _rowNum * _colNum; ++i)
        {
            res.push_back(_matrix[i] - other._matrix[i]);
        }
        return Matrix(_rowNum, _colNum, res);
    }

    Matrix<T> operator*(const Matrix<T> &other) const
    {
//        cout << _rowNum << _colNum << other._rowNum << other._colNum;
        vector<T> res;
        Matrix<int> temp;
        if (_colNum != other._rowNum)
        {
            throw MyException("Error - Unmatching dimensions");
        }
        auto it1 = _matrix.begin();
        auto it2 = other._matrix.begin();

        for (int i = 0; i < _rowNum; ++i)
        {
            for (int j = 0; j < other._colNum; ++j)
            {
                int sum = 0;
                for (int k = 0; k < _colNum; ++k)
                {
                    sum += _matrix[i * _colNum + k] * other._matrix[j + k * other._colNum];
                }
                res.push_back(sum);
            }
        }
        return Matrix<int>(_rowNum, other._colNum, res);
    }

    bool operator==(const Matrix<T> &other)
    {
        return (_colNum == other._colNum && _rowNum == other._rowNum &&
                std::equal(_matrix.begin(), _matrix.end(), other._matrix.begin()));
    }

    bool operator!=(const Matrix<T> &other)
    {
        return (_colNum != other._colNum || _rowNum != other._rowNum ||
                !equal(_matrix.begin(), _matrix.end(), other._matrix.begin()));
    }

    bool isSquareMatrix()
    {
        return _rowNum == _colNum;
    }

    Matrix<T> trans()
    {
        if (!isSquareMatrix())
        {
            throw MyException("Error - can't transpose a non-square matrix");
        }
        vector<T> res;
        for (int i = 0; i < _rowNum; ++i)
        {
            for (int j = 0; j < _colNum; ++j)
            {
                res.push_back(_matrix[i + j * _rowNum]);
            }
        }
        return Matrix<T>(_rowNum, _colNum, res);
    }

    T operator()(unsigned int i, unsigned int j) const
    {
        return _matrix[i * _colNum + j];
    }

    T &operator()(unsigned int i, unsigned int j)
    {
        return _matrix[i * _colNum + j];
    }

    typedef std::vector<std::string>::iterator const_iterator;

    const_iterator begin()
    { return _matrix.cbegin(); }

    const_iterator end()
    { return _matrix.cend(); }

    int cols()
    { return _colNum; }

    int rows()
    { return _rowNum; }

};


template<>
Matrix<Complex> Matrix<Complex>::trans()
{
    if (!isSquareMatrix())
    {
        throw MyException("Error - can't transpose a non-square matrix");
    }
    vector<Complex> res;
    for (int i = 0; i < _rowNum; ++i)
    {
        for (int j = 0; j < _colNum; ++j)
        {
            res.push_back(_matrix[i + j * _rowNum].conj());
        }
    }
    return Matrix<Complex>(_rowNum, _colNum, res);
}


#endif //EX3_MATRIX_HPP
