//
// Created by אלה on 06/01/2019.
//
#ifndef EX3_MATRIX_HPP
#define EX3_MATRIX_HPP

#include <vector>
#include <iostream>
#include "Complex.h"

using namespace std;

/**
 * A generic exception class for handeling matrix exceptions.
 * @param messege - the error message to be printed.
 */
class MatrixException : public std::runtime_error
{
public:
    /**
     * A constructor for thr message
     * @param messege
     */
    explicit MatrixException(const char *messege) : runtime_error(messege), _message(messege)
    {}

    /**
     * An override for the what method
     * @return
     */
    const char *what() const noexcept override
    {
        return _message;
    }

private:
    /** The message to be printed */
    const char *_message;
};

/**
 * This class represents a Template Matrix for ints, doubles and complex numbers.
 * The template matrix supports addition, multipication and transpose functions.
 */
template<class T>
class Matrix
{
private:
    /** number of columns */
    unsigned int _colNum;
    /** number of rows */
    unsigned int _rowNum;
    /**
     * A vector representing the matrix */
    vector<T> _matrix;

public:
    // ------------------------------ constructors ------------------------------ //

    /**
     * A default constructor returning a 1x1 matrix with 0 in it.
     */
    Matrix() try: _colNum((unsigned int) 1), _rowNum((unsigned int) 1)
    {
        _matrix.push_back(0);
    }
    catch (exception &e) {
        throw MatrixException("Error - initialization failed due to allocation fail.");
    }

    /**
     * A constructor receiving unsigned ints for number of rows and coloumns -
     * and returning a matrix with 0 in it.
     * @param rows - unsigned int
     * @param cols - unsigned int
     */
    Matrix(const unsigned int rows, const unsigned int cols) try : _colNum(cols), _rowNum(rows),
                                                               _matrix(rows * cols, 0)
    {}
    catch (exception &e) {
        throw MatrixException("Error - initialization failed due to allocation fail.");
    }

    /**
     * A copy constructor.
     * @param other - the matrix to be copied.
     */
    Matrix(const Matrix &other) = default;

    /**
     * A constructor receiving ints for the row and column count and a vector - and creates a matrix
     * with the values of the vector accordingly.
     * @param rows - unsigned int
     * @param cols - unsigned int
     * @param cells - a vector
     */
    Matrix(const unsigned int rows, const unsigned int cols, const vector<T> &cells) : _colNum(cols),
                                                                                       _rowNum(rows)
    {
        for (auto &i : cells)
        {
            _matrix.push_back(i);
        }
    }

    /**
     * A default deconstructor.
     */
    ~Matrix() = default;

    // ------------------------------ operators ------------------------------ //

    /**
     * An overload of the std::cout operator.
     * @param out - an os stream.
     * @param mat - the matrix to be printed.
     * @return the ostream
     */
    friend ostream &operator<<(ostream &out, const Matrix &mat)
    {
        int t = 0;
        for (unsigned int i = 0; i < mat._rowNum; ++i)
        {
            for (unsigned int j = 0; j < mat._colNum; ++j)
            {
                out << mat._matrix[t++] << "\t";
            }
            out << endl;
        }
        return out;
    }

    /**
     * An over load to the default copy constructor. This function throws an exception if the new and given matrix
     * dimensions do not match.
     * @param other - the matrix to be copied
     * @return this
     */
    Matrix<T> &operator=(const Matrix<T> &other) = default;

    Matrix<T> operator+(const Matrix<T> &other) const
    {
        vector<T> res;
        if (other._colNum != _colNum || other._rowNum != _rowNum)
        {
            throw MatrixException("Error - Unmatching dimensions");
        }
        for (unsigned int i = 0; i < _rowNum * _colNum; ++i)
        {
            res.push_back(_matrix[i] + other._matrix[i]);
        }
        return Matrix(_rowNum, _colNum, res);
    }

    /**
     * An over load to the - operator. This function throws an exception if the new and given matrix
     * dimensions do not match.
     * @param other - the matrix to be substracted.
     * @return a new matrix
     */
    Matrix<T> operator-(const Matrix<T> &other) const
    {
        vector<T> res;
        if (other._colNum != _colNum || other._rowNum != _rowNum)
        {
            throw MatrixException("Error - Unmatching dimensions");
        }
        for (unsigned int i = 0; i < _rowNum * _colNum; ++i)
        {
            res.push_back(_matrix[i] - other._matrix[i]);
        }
        return Matrix(_rowNum, _colNum, res);
    }

    /**
     * An over load to the * operator. This function throws an exception if the new and given matrix
     * dimensions do not match.
     * @param other - the matrix to be multiplied.
     * @return a new matrix
     */
    Matrix<T> operator*(const Matrix<T> &other) const
    {
        vector<T> res;
        Matrix<T> temp;
        if (_colNum != other._rowNum)
        {
            throw MatrixException("Error - Unmatching dimensions");
        }
        for (unsigned int i = 0; i < _rowNum; ++i)
        {
            for (unsigned int j = 0; j < other._colNum; ++j)
            {
                int sum = 0;
                for (unsigned int k = 0; k < _colNum; ++k)
                {
                    sum += _matrix[i * _colNum + k] * other._matrix[j + k * other._colNum];
                }
                res.push_back(sum);
            }
        }
        return Matrix<T>(_rowNum, other._colNum, res);
    }

    /**
     * An overload to the == operator.
     * @param other - the matrix to be compared.
     * @return - true if the matrixs are equal, false otherwise.
     */
    bool operator==(const Matrix<T> &other)
    {
        return (_colNum == other._colNum && _rowNum == other._rowNum &&
                std::equal(_matrix.begin(), _matrix.end(), other._matrix.begin()));
    }


    /**
     * An overload to the != operator.
     * @param other - the matrix to be compared.
     * @return - false if the matrixs are equal, true otherwise.
     */
    bool operator!=(const Matrix<T> &other)
    {
        return (_colNum != other._colNum || _rowNum != other._rowNum ||
                !equal(_matrix.begin(), _matrix.end(), other._matrix.begin()));
    }

    /**
     * @return true if the matrix is squared.
     */
    bool isSquareMatrix()
    {
        return _rowNum == _colNum;
    }

    /**
     * returns the transpose of the current matrix. throws an exception if the matrix is not square.
     * @return
     */
    Matrix<T> trans()
    {
        if (!isSquareMatrix())
        {
            throw MatrixException("Error - can't transpose a non-square matrix");
        }
        vector<T> res;
        for (unsigned int i = 0; i < _rowNum; ++i)
        {
            for (unsigned int j = 0; j < _colNum; ++j)
            {
                res.push_back(_matrix[i + j * _rowNum]);
            }
        }
        return Matrix<T>(_rowNum, _colNum, res);
    }

    /**
     * An overload to the const () operator - returns the T object in the i row, j col.
     * Throws an ecxeption in case of index out of range.
     * @param i - row index
     * @param j - column index
     * @return - a T object located in the matrix[i][j]
     */
    T operator()(unsigned int i, unsigned int j) const
    {
        try
        {
            return _matrix.at(i * _colNum + j);
        } catch (exception &e)
        {
            throw MatrixException("User tried to access an index out of range");
        }
    }

    /**
     * An overload to the const () operator - returns a reference to the T object in the i row, j col.
     * Throws an ecxeption in case of index out of range.
     * @param i - row index
     * @param j - column index
     * @return - a reference to the T object located in the matrix[i][j]
     */
    T &operator()(unsigned int i, unsigned int j)
    {
        try
        {
            return _matrix.at(i * _colNum + j);
        } catch (exception &e)
        {
            throw MatrixException("User tried to access an index out of range");
        }
    }

    /* a typedef typename for the matrix iterator */
    typedef typename std::vector<T>::const_iterator const_iterator;

    /**
     * @return an iterator for the first T object in the matrix
     */
//    const_iterator begin() const
    typename std::vector<T>::const_iterator begin() const
    { return _matrix.cbegin(); }

    /**
     * @return an iterator for the location after the last T object in the matrix
     */
    const_iterator end() const
    {
        return _matrix.cend();
    }

    /**
     * @return the number of columns in the matrix
     */
    unsigned int cols()
    {
        return _colNum;
    }

    /**
     * @return the number of rows in the matrix
     */
    unsigned int rows()
    {
        return _rowNum;
    }

};


/**
 * A spacialization for Complex numbers - uses a special algorithm for the transpose method.
 * @return the transpose matrix of a given complex numbers matrix.
 */
template<>
Matrix<Complex> Matrix<Complex>::trans()
{
    if (!isSquareMatrix())
    {
        throw MatrixException("Error - can't transpose a non-square matrix");
    }
    vector<Complex> res;
    for (unsigned int i = 0; i < _rowNum; ++i)
    {
        for (unsigned int j = 0; j < _colNum; ++j)
        {
            res.push_back((_matrix[i + j * _rowNum].conj()));
        }
    }
    return Matrix<Complex>(_rowNum, _colNum, res);
}


#endif //EX3_MATRIX_HPP
