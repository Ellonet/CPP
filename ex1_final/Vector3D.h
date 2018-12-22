//
// Created by אלה on 08/12/2018.
//

#ifndef CPP_EX1_VECTOR3D_H
#define CPP_EX1_VECTOR3D_H
#include <stdlib.h>
#include <iostream>
using namespace std;

/**
 * This class represents a vector which holds 3 numbers, and enables
 * all the vector arithmetics.
 */
class Vector3D
{
private:
    /**
     * A private initialization function - receiving 3 doubles and placing them in the vector.
     * @param v1 - first number of the vector
     * @param v2 - second number of the vector
     * @param v3 - third number of the vector
     */
    void _init(double v1, double v2, double v3);

public:
    // an array representing the _vector
    double _vector[3];

    /**
     * A default constractor - initializing the vector to hold 3 zeros [0,0,0]
     */
    Vector3D();

    /**
     * A constractor receiving 3 doubles and initializes the vector with those numbers
     * @param d1 - first double
     * @param d2 - second double
     * @param d3 - third double
     */
    Vector3D(double d1, double d2, double d3);

    /**
     * A copy constractor - initializing a vector with the parameters of the given vector
     * @param other - the vector to be copied.
     */
    Vector3D(const Vector3D &other);

    /**
     * A constractor that initializes the vector with the values of a given array of 3 doubles.
     * @param arr - the array to initialize the vector from.
     */
    explicit Vector3D(double (&arr)[3]);

    /**
     * An overload of the << function - printing the vector
     * @param stream - the stream to which the vector is to be printed
     * @param vector - the vector to print
     * @return the stream to print
     */
    friend ostream &operator<<(ostream &stream, const Vector3D &vector);

    /**
     * An overloading function for receiving data from the user
     * @param is - the input stream
     * @param vector - the vector created from the user's input
     * @return the input stream
     */
    friend istream &operator>>(istream &is, Vector3D &vector);

    /**
     * An overloading function for the + operator: adds this vector and the given vector and return a new vector
     * @param other - the second vector to be added
     * @return - a new vector.
     */
    const Vector3D operator+(const Vector3D &other) const;

    /**
     * An overloading function for the - operator: subtracts 2 vectors and return a new vector
     * @param other - the vector subtracted
     * @return - a new vector.
     */
    const Vector3D operator-(const Vector3D &other) const;

    /**
     * An overload for the += operator: adds the given vector the current one
     * @param other - the vector to be added to this vector
     * @return a pointer to this vector.
     */
    Vector3D &operator+=(const Vector3D &other);

    /**
     * An overload for the -= operator: subtracts the given vecotor the current one
     * @param other - the vector to be subtracted from this vector
     * @return a pointer to this vector.
     */
    Vector3D &operator-=(const Vector3D &other);

    /**
     * An overload for the += operator: adds the given number to each one of the current vector
     * @param num - the number to be added
     * @return a pointer to this vector
     */
    Vector3D &operator+=(double num);

    /**
     * An overload for the -= operator: subtract the given number from each one of the current vector
     * @param num - the number to be subtracted
     * @return a pointer to this vector
     */
    Vector3D &operator-=(double num);

    /**
     * An overload to the - operator: negates the given vector
     * @return a new vector.
     */
    const Vector3D &operator-();

    /**
     * An overload to the / operator: divides each value of the given vector by the given number
     * @param other - the vector to be divided
     * @param num - the dividor
     * @return a new vector.
     */
    friend Vector3D operator/(const Vector3D &other, double num);

    /**
     * An overload to the * operator: multiplies each value of the given vactor by the given number
     * @param other - the vector to be multiplied
     * @param num - the multiplier
     * @return - a new vector
     */
    friend Vector3D operator*(const Vector3D &other, double num);

    /**
     * An overload to the * operator: multiplies each value of the given vactor by the given number
     * @param num - the multiplier
     * @param other - the vector to be multiplied
     * @return - a new vector
     */
    friend Vector3D operator*(double num, const Vector3D &other);

    /**
     * An overload to the *= operator: multiplies each value of the current  vactor by the given number
     * @param num - the multiplier
     * @return a pointer to this vector
     */
    Vector3D &operator*=(double num);

    /**
     * An overload to the /= operator: divides each value of the current  vactor by the given number
     * @param num - the multiplier
     * @return a pointer to this vector
     */
    Vector3D &operator/=(double num);

    /**
     * An overload of the | operator: returns the distance between 2 vectors.
     * @param other - the other vector to get distance from
     * @return a double representing the distance
     */
    const double operator|(Vector3D &other);

    /**
     * An overload of the * operator: multiplies 2 vectors
     * @param other - the vector to be multiplied
     * @return a double representing the result
     */
    const double operator*(Vector3D &other) const;

    /**
     * An overload of the ^ operator: calculates the radian angle of this vector.
     * @param other - the vector to calculate
     * @return a double representing the angle.
     */
    const double operator^(Vector3D &other);

    /**
     * An overloading of the = operator: a shallow copy
     * @param other - the vector to be copied from
     * @return the pointer to this vector.
     */
    Vector3D &operator=(const Vector3D &other);

    /**
     * An overload to the [] operator.
     * @param index
     * @return the value of the vector in the index location
     */
    const double operator[](int index) const;

    /**
     * An overload to the [] operators: allowing changing the values of the vector the index location
     * @param index
     * @return a reference to the desired value
     */
    double &operator[](int index);


     /**
     * A function calculating the 2nd norm of the given vector
     * @return a double representing the norm
     */
    const double norm();

    /**
     * This function calculates the distance between 2 vectors.
     * @param other - the vector to calculate the distance from.
     * @return a double representing the distance
     */
    const double dist(Vector3D &other);
};

#endif //CPP_EX1_VECTOR3D_H
