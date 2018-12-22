//
// Created by אלה on 10/12/2018.
//

#ifndef CPP_EX1_MATRIX3D_H
#define CPP_EX1_MATRIX3D_H

#include <stdlib.h>
#include <iostream>
#include "Vector3D.h"

using namespace std;

/**
 * This class represents a 3X3 matrix, and enables all the vector arithmetics.
 */
class Matrix3D
{
private:
    /**
     * A private initialization function - receiving 3 Vector3D and generates the Matrix3D.
     * @param v1 - first vector
     * @param v2 - second vector
     * @param v3 - third vector
     */
    void _init(Vector3D v1, Vector3D v2, Vector3D v3);

    Vector3D v1;
    Vector3D v2;
    Vector3D v3;

public:
    /**
     * A constructor that initializes the matrix all zeros.
     */
    Matrix3D();

    /**
     * A constructor that initializes the matrix with the given number in the slant.
     * @param num - the number to be placed in the slant.
     */
    explicit Matrix3D(double num);

    /**
     * A constructor that initializes the matrix with the given 9 doubles.
     * @param num1, num2, num3, num4, num5, num6, num7, num8, num9 - the initialization numbers
     */
    Matrix3D(double num1, double num2, double num3, double num4, double num5, double num6, double num7, double num8,
             double num9);

    /**
     * A constractor that initializes the Matrix with the values of a given array of 9 doubles.
     * @param arr - the array
     */
    explicit Matrix3D(double (&arr)[9]);

    /**
     * A constractor that initializes the vector with the values of a given 2D array of 3X3 doubles.
     * @param arr - the 2D array
     */
    explicit Matrix3D(double (&arr)[3][3]);

    /**
     * A constractor that initializes the Matrix with the values of 3 given Vector3D vectors.
     * @param v1 - first vector
     * @param v2 - second vector
     * @param v3 - third vector
     */
    Matrix3D(Vector3D v1, Vector3D v2, Vector3D v3);
<<<<<<< HEAD

    /**
     * A copy constractor - initializing a matrix with the parameters of the given matrix
     * @param other - the matrix to be copied.
     */
    Matrix3D(Matrix3D &other);

    /**
     * An overload of the << function - printing the matrix
     * @param stream - the stream to which the matrix is to be printed
     * @param matrix - the vector to print
     * @return the stream to print
     */
    friend ostream &operator<<(ostream &out, const Matrix3D &matrix);

    /**
     * An overloading function for receiving data from the user
     * @param is - the input stream
     * @param matrix - the matrix created from the user's input
     * @return the input stream
     */
    friend istream &operator>>(istream &in, Matrix3D &matrix);

    /**
     * An overload for the -= operator: subtracts the given matrix from the current one
     * @param other - the matrix to be subtracted from this matrix
     * @return a pointer to this matrix
     */
    Matrix3D &operator-=(Matrix3D &other);

    /**
     * An overload for the += operator: adds the given matrix to the current one
     * @param other - the matrix to be added to this matrix
     * @return a pointer to this matrix
     */
    Matrix3D &operator+=(Matrix3D &other);

    /**
     * An overload for the *= operator: multiplies this matrix with the given matrix.
     * @param other - the given matrix
     * @return a pointer to this matrix
     */
    Matrix3D &operator*=(Matrix3D &other);

    /**
     * An overloading function for the + operator: adds this matrix and the given matrix and return a new matrix
     * @param other - the second matrix to be added
     * @return - a new matrix.
     */
=======
    Matrix3D(const Matrix3D &other);
    friend ostream& operator<<(ostream &out, const Matrix3D& matrix);
    friend istream& operator>>(istream &in, Matrix3D& matrix);
    Matrix3D& operator-=(Matrix3D &other);
    Matrix3D& operator+=(Matrix3D &other);
    Matrix3D& operator*=(Matrix3D &other);
>>>>>>> 7240473f9cee46f291802a5354137df4cf0d95dc
    Matrix3D operator+(Matrix3D &other);

    /**
     * An overloading function for the - operator: substracts this matrix and the given matrix and return a new matrix
     * @param other - the second matrix to be subtracted
     * @return - a new matrix.
     */
    Matrix3D operator-(Matrix3D &other);

    /**
     * An overloading function for the * operator: multiplies this matrix and the given matrix and return a new matrix
     * @param other - the second matrix to be multiplied
     * @return - a new matrix.
     */
    Matrix3D operator*(Matrix3D &other);

    /**
     * An overload for the *= operator: multiplies this matrix with the given number.
     * @param other - the given number
     * @return a pointer to this matrix
     */
    Matrix3D &operator*=(double num);

    /**
     * An overload for the /= operator: divides this matrix with the given number.
     * @param other - the given number
     * @return a pointer to this matrix
     */
    Matrix3D &operator/=(double num);

    /**
     * An overload for the * operator: multiplies this matrix with the given Vector3D vector.
     * @param vector
     * @return a new vector
     */
    Vector3D operator*(Vector3D &vector);

    /**
     * An overloading of the = operator: a shallow copy
     * @param other - the matrix to be copied from
     * @return the pointer to this matrix.
     */
    Matrix3D &operator=(const Matrix3D &other);

    /**
     * An overload to the [] operator.
     * @param index
     * @return the value of the matrix in the index location
     */
    Vector3D operator[](int index) const;

    /**
     * An overload to the [] operators: allowing changing the values of the vector the index location
     * @param index
     * @return a reference to the desired value
     */
    Vector3D &operator[](int index);

    /**
     * This function returns a Vector3D vector representing the row of the matrix in the given index.
     * @param index
     * @return a Vector3D vector
     */
    Vector3D row(int index);
<<<<<<< HEAD

    /**
     * This function returns a Vector3D vector representing the column of the matrix in the given index.
     * @param index
     * @return a Vector3D vector
     */
    Vector3D column(int index);

    /**
     * This functoin calculates the trace of this matrix.
     * @return - a double representing the trace.
     */
=======
    Vector3D column(int index);
>>>>>>> 7240473f9cee46f291802a5354137df4cf0d95dc
    double trace();

    /**
     * This functoin calculates the determinant of this matrix.
     * @return - a double representing the determinant.
     */
    double determinant();

};

#endif //CPP_EX1_MATRIX3D_H
