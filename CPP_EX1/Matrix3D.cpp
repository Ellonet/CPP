//
// Created by אלה on 10/12/2018.
//

#include <iostream>
#include <stdlib.h>
#include "Matrix3D.h"

using namespace std;

/**
 * A private initialization function - receiving 3 Vector3D and generates the Matrix3D.
 * @param v1 - first vector
 * @param v2 - second vector
 * @param v3 - third vector
 */
void Matrix3D::_init(Vector3D v1, Vector3D v2, Vector3D v3)
{
    this->v1 = v1;
    this->v2 = v2;
    this->v3 = v3;
}

//---------------------------------- constractors ----------------------------------//
/**
 * A constructor that initializes the matrix all zeros.
 */
Matrix3D::Matrix3D()
{
    Vector3D v1, v2, v3;
    _init(v1, v2, v3);
}

/**
 * A constructor that initializes the matrix with the given number in the slant.
 * @param num - the number to be placed in the slant.
 */
Matrix3D::Matrix3D(double num)
{
    Vector3D v1(num, 0, 0);
    Vector3D v2(0, num, 0);
    Vector3D v3(0, 0, num);
    _init(v1, v2, v3);
}

/**
 * A constructor that initializes the matrix with the given 9 doubles.
 * @param num1, num2, num3, num4, num5, num6, num7, num8, num9 - the initialization numbers
 */
Matrix3D::Matrix3D(double num1, double num2, double num3, double num4, double num5, double num6, double num7,
                   double num8, double num9)
{
    Vector3D v1(num1, num2, num3);
    Vector3D v2(num4, num5, num6);
    Vector3D v3(num7, num8, num9);
    _init(v1, v2, v3);
}

/**
 * A constractor that initializes the Matrix with the values of a given array of 9 doubles.
 * @param arr - the array
 */
Matrix3D::Matrix3D(double (&arr)[9])
{
    Vector3D v1(arr[0], arr[1], arr[2]);
    Vector3D v2(arr[3], arr[4], arr[5]);
    Vector3D v3(arr[6], arr[7], arr[8]);
    _init(v1, v2, v3);
}

/**
 * A constractor that initializes the vector with the values of a given 2D array of 3X3 doubles.
 * @param arr - the 2D array
 */
Matrix3D::Matrix3D(double (&arr)[3][3])
{
    Vector3D v1(arr[0][0], arr[0][1], arr[0][2]);
    Vector3D v2(arr[1][0], arr[1][1], arr[1][2]);
    Vector3D v3(arr[2][0], arr[2][1], arr[2][2]);
    _init(v1, v2, v3);
}

/**
 * A constractor that initializes the Matrix with the values of 3 given Vector3D vectors.
 * @param v1 - first vector
 * @param v2 - second vector
 * @param v3 - third vector
 */
Matrix3D::Matrix3D(Vector3D v1, Vector3D v2, Vector3D v3)
{
    _init(v1, v2, v3);
}

/**
 * A copy constractor - initializing a matrix with the parameters of the given matrix
 * @param other - the matrix to be copied.
 */
Matrix3D::Matrix3D(Matrix3D &other)
{
    Vector3D v1 = other.v1;
    Vector3D v2 = other.v2;
    Vector3D v3 = other.v3;
    _init(v1, v2, v3);
}

//---------------------------------- stream overloading ----------------------------------//
/**
 * An overload of the << function - printing the matrix
 * @param stream - the stream to which the matrix is to be printed
 * @param matrix - the vector to print
 * @return the stream to print
 */
ostream &operator<<(ostream &outStream, const Matrix3D &matrix)
{
    return outStream << matrix.v1 << matrix.v2 << matrix.v3;
}

/**
 * An overloading function for receiving data from the user
 * @param is - the input stream
 * @param matrix - the matrix created from the user's input
 * @return the input stream
 */
istream &operator>>(istream &inStream, Matrix3D &matrix)
{
    inStream >> matrix.v1;
    inStream >> matrix.v2;
    inStream >> matrix.v3;
    return inStream;
}

//---------------------------------- operator overloading ----------------------------------//
/**
 * An overload for the -= operator: subtracts the given matrix from the current one
 * @param other - the matrix to be subtracted from this matrix
 * @return a pointer to this matrix
 */
Matrix3D &Matrix3D::operator-=(Matrix3D &other)
{
    this->v1 -= other.v1;
    this->v2 -= other.v2;
    this->v3 -= other.v3;
    return *this;
}

/**
 * An overload for the += operator: adds the given matrix to the current one
 * @param other - the matrix to be added to this matrix
 * @return a pointer to this matrix
 */
Matrix3D &Matrix3D::operator+=(Matrix3D &other)
{
    this->v1 += other.v1;
    this->v2 += other.v2;
    this->v3 += other.v3;
    return *this;
}

/**
 * An overload for the *= operator: multiplies this matrix with the given matrix.
 * @param other - the given matrix
 * @return a pointer to this matrix
 */
Matrix3D &Matrix3D::operator*=(Matrix3D &other)
{
    Vector3D col1, col2, col3, row1, row2, row3;
    col1 = this->column(0);
    col2 = this->column(1);
    col3 = this->column(2);
    row1 = other.row(0);
    row2 = other.row(1);
    row3 = other.row(2);
    this->v1[0] = row1 * col1;
    this->v1[1] = row1 * col2;
    this->v1[2] = row1 * col3;
    this->v2[0] = row2 * col1;
    this->v2[1] = row2 * col2;
    this->v2[2] = row2 * col3;
    this->v3[0] = row3 * col1;
    this->v3[1] = row3 * col2;
    this->v3[2] = row3 * col3;
    return *this;
}

/**
 * An overloading function for the + operator: adds this matrix and the given matrix and return a new matrix
 * @param other - the second matrix to be added
 * @return - a new matrix.
 */
Matrix3D Matrix3D::operator+(Matrix3D &other)
{
    Matrix3D res;
    Vector3D v1, v2, v3;
    v1 = this->v1 + other.v1;
    v2 = this->v2 + other.v2;
    v3 = this->v3 + other.v3;
    res = Matrix3D(v1, v2, v3);
    return res;
}

/**
 * An overloading function for the - operator: substracts this matrix and the given matrix and return a new matrix
 * @param other - the second matrix to be subtracted
 * @return - a new matrix.
 */
Matrix3D Matrix3D::operator-(Matrix3D &other)
{
    Matrix3D res;
    Vector3D v1, v2, v3;
    v1 = this->v1 - other.v1;
    v2 = this->v2 - other.v2;
    v3 = this->v3 - other.v3;
    res = Matrix3D(v1, v2, v3);
    return res;
}

/**
  * An overloading function for the * operator: multiplies this matrix and the given matrix and return a new matrix
  * @param other - the second matrix to be multiplied
  * @return - a new matrix.
  */
Matrix3D Matrix3D::operator*(Matrix3D &other)
{
    Matrix3D res;
    Vector3D v1, v2, v3;
    Vector3D col1, col2, col3, row1, row2, row3;
    col1 = this->column(0);
    col2 = this->column(1);
    col3 = this->column(2);
    row1 = other.row(0);
    row2 = other.row(1);
    row3 = other.row(2);
    v1 = Vector3D(row1 * col1, row1 * col2, row1 * col3);
    v2 = Vector3D(row2 * col1, row2 * col2, row2 * col3);
    v3 = Vector3D(row3 * col1, row3 * col2, row3 * col3);
    res = Matrix3D(v1, v2, v3);
    return res;
}

/**
 * An overload for the *= operator: multiplies this matrix with the given number.
 * @param other - the given number
 * @return a pointer to this matrix
 */
Matrix3D &Matrix3D::operator*=(double num)
{
    this->v1 *= num;
    this->v2 *= num;
    this->v3 *= num;
    return *this;
}

/**
 * An overload for the /= operator: divides this matrix with the given number.
 * @param other - the given number
 * @return a pointer to this matrix
 */
Matrix3D &Matrix3D::operator/=(double num)
{
    this->v1 /= num;
    this->v2 /= num;
    this->v3 /= num;
    return *this;
}

/**
 * An overload for the * operator: multiplies this matrix with the given Vector3D vector.
 * @param vector
 * @return a new vector
 */
Vector3D Matrix3D::operator*(Vector3D &vector)
{
    Vector3D res;
    res[0] = this->v1 * vector;
    res[1] = this->v2 * vector;
    res[2] = this->v3 * vector;
    return res;
}

/**
 * An overloading of the = operator: a shallow copy
 * @param other - the matrix to be copied from
 * @return the pointer to this matrix.
 */
Vector3D Matrix3D::operator[](int index) const
{
    Vector3D res;
    if (index == 0)
    {
        res = this->v1;
    } else if (index == 1)
    {
        res = this->v2;
    } else if (index == 2)
    {
        res = this->v3;
    }
    else
    {
        std::cerr << "Error - out of range";
        exit(1);
    }
    return res;
}

/**
 * An overload to the [] operator.
 * @param index
 * @return the value of the matrix in the index location
 */
Vector3D &Matrix3D::operator[](int index)
{
    if (index == 0)
    {
        return this->v1;

    } else if (index == 1)
    {
        return this->v2;
    } else if (index == 2)
    {
        return this->v3;
    }
    else
    {
        cerr << "Error - out of range";
        exit(1);
    }
}

/**
 * An overload to the [] operators: allowing changing the values of the vector the index location
 * @param index
 * @return a reference to the desired value
 */
Matrix3D &Matrix3D::operator=(const Matrix3D &other) = default;

//---------------------------------- additional functions ----------------------------------//
/**
 * This function returns a Vector3D vector representing the row of the matrix in the given index.
 * @param index
 * @return a Vector3D vector
 */
Vector3D Matrix3D::row(int index)
{
    Vector3D res;
    if (index == 0)
    {
        res = this->v1;
    }
    else if (index == 1)
    {
        res = this->v2;
    }
    else if (index == 2)
    {
        res = this->v3;
    }
    else
    {
        cerr << "Error - out of range";
        exit(1);
    }
    return res;
}

/**
 * This function returns a Vector3D vector representing the column of the matrix in the given index.
 * @param index
 * @return a Vector3D vector
 */
Vector3D Matrix3D::column(int index)
{
    Vector3D res;
    if (index == 0)
    {
        res = Vector3D(this->v1[0], this->v2[0], this->v3[0]);
    }
    else if (index == 1)
    {
        res = Vector3D(this->v1[1], this->v2[1], this->v3[1]);
    }
    else if (index == 2)
    {
        res = Vector3D(this->v1[3], this->v2[2], this->v3[2]);
    }
    else
    {
        cerr << "Error - out of range";
        exit(1);
    }
    return res;
}

/**
 * This functoin calculates the trace of this matrix.
 * @return - a double representing the trace.
 */
double Matrix3D::trace()
{
    return this->v1[0] + this->v2[1] + this->v3[2];
}

/**
 * This functoin calculates the determinant of this matrix.
 * @return - a double representing the determinant.
 */
double Matrix3D::determinant()
{
    double a, b, c, d, e, f, g, h, i;
    a = this->v1[0];
    b = this->v1[1];
    c = this->v1[2];
    d = this->v2[0];
    e = this->v2[1];
    f = this->v2[2];
    g = this->v3[0];
    h = this->v3[1];
    i = this->v3[2];
    return a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
}