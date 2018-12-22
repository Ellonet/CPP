//
// Created by אלה on 08/12/2018.
//
#include <iostream>
#include <math.h>
#include <string>
#include "Vector3D.h"

using namespace std;


//---------------------------------- constructors ----------------------------------//
/**
 * A private initialization function - receiving 3 doubles and placing them in the vector.
 * @param v1 - first number of the vector
 * @param v2 - second number of the vector
 * @param v3 - third number of the vector
 */
void Vector3D::_init(double v1, double v2, double v3)
{
    this->vector[0] = v1;
    this->vector[1] = v2;
    this->vector[2] = v3;
}

/**
 * A default constractor - initializing the vector to hold 3 zeros [0,0,0]
 */
Vector3D::Vector3D()
{
    _init(0, 0, 0);
}

/**
 * A constractor receiving 3 doubles and initializes the vector with those numbers
 * @param d1 - first double
 * @param d2 - second double
 * @param d3 - third double
 */
Vector3D::Vector3D(double d1, double d2, double d3)
{
    _init(d1, d2, d3);
}


/**
 * A constractor that initializes the vector with the values of a given array of 3 doubles.
 * @param arr - the array to initialize the vector from.
 */
Vector3D::Vector3D(double (&arr)[3])
{
    _init(arr[0], arr[1], arr[2]);
}

<<<<<<< HEAD
/**
 * A copy constractor - initializing a vector with the parameters of the given vector
 * @param other - the vector to be copied.
 */
Vector3D::Vector3D(Vector3D &other)
{
=======
Vector3D::Vector3D(const Vector3D &other) {
>>>>>>> 7240473f9cee46f291802a5354137df4cf0d95dc
    double d1 = other.vector[0];
    double d2 = other.vector[1];
    double d3 = other.vector[2];
    _init(d1, d2, d3);
}

<<<<<<< HEAD
//---------------------------------- streams overloading ----------------------------------//
/**
 * An overload of the << function - printing the vector
 * @param stream - the stream to which the vector is to be printed
 * @param vector - the vector to print
 * @return the stream to print
 */
ostream &operator<<(ostream &outStream, const Vector3D &other)
{
    return outStream << other.vector[0] << " " << other.vector[1] << " " << other.vector[2] << endl;
=======
///////////// streams overloading /////////////
ostream &operator<<(ostream &outStream, const Vector3D &other) {
    return outStream << other.vector[0] << " " << other.vector[1] << " " << other.vector[2];
>>>>>>> 7240473f9cee46f291802a5354137df4cf0d95dc
}

/**
 * An overloading function for receiving data from the user
 * @param is - the input stream
 * @param vector - the vector created from the user's input
 * @return the input stream
 */
istream &operator>>(istream &inStream, Vector3D &vector)
{
    inStream >> vector.vector[0];
    inStream >> vector.vector[1];
    inStream >> vector.vector[2];
    return inStream;
}


//---------------------------------- operator overloading ----------------------------------//
/**
 * An overloading function for the + operator: adds this vector and the given vector and return a new vector
 * @param other - the second vector to be added
 * @return - a new vector.
 */
const Vector3D Vector3D::operator+(const Vector3D &other)
{
    Vector3D res;
    res.vector[0] = this->vector[0] + other.vector[0];
    res.vector[1] = this->vector[1] + other.vector[1];
    res.vector[2] = this->vector[2] + other.vector[2];
    return res;
}

/**
 * An overloading function for the - operator: subtracts 2 vectors and return a new vector
 * @param other - the vector subtracted
 * @return - a new vector.
 */
const Vector3D Vector3D::operator-(const Vector3D &other)
{
    Vector3D res;
    res.vector[0] = this->vector[0] - other.vector[0];
    res.vector[1] = this->vector[1] - other.vector[1];
    res.vector[2] = this->vector[2] - other.vector[2];
    return res;
}

/**
 * An overload for the += operator: adds the given vector the current one
 * @param other - the vector to be added to this vector
 * @return a pointer to this vector.
 */
Vector3D &Vector3D::operator+=(const Vector3D &other)
{
    *this = *this + other;
    return *this;
}

/**
 * An overload for the += operator: adds the given number to each one of the current vector
 * @param num - the number to be added
 * @return a pointer to this vector
 */
Vector3D &Vector3D::operator+=(double num)
{
    this->vector[0] += num;
    this->vector[1] += num;
    this->vector[2] += num;
    return *this;
}

/**
 * An overload for the -= operator: subtracts the given vecotor the current one
 * @param other - the vector to be subtracted from this vector
 * @return a pointer to this vector.
 */
Vector3D &Vector3D::operator-=(const Vector3D &other)
{
    *this = *this - other;
    return *this;
}

/**
 * An overload for the -= operator: subtract the given number from each one of the current vector
 * @param num - the number to be subtracted
 * @return a pointer to this vector
 */
Vector3D &Vector3D::operator-=(double num)
{
    this->vector[0] -= num;
    this->vector[1] -= num;
    this->vector[2] -= num;
    return *this;
}

<<<<<<< HEAD
/**
 * An overload to the - operator: negates the given vector
 * @return a new vector.
 */
const Vector3D &Vector3D::operator-()
{
=======
Vector3D operator-(const Vector3D &vector) {
>>>>>>> 7240473f9cee46f291802a5354137df4cf0d95dc
    Vector3D zero;
    return zero - vector;
}

/**
 * An overload to the * operator: multiplies each value of the given vactor by the given number
 * @param other - the vector to be multiplied
 * @param num - the multiplier
 * @return - a new vector
 */
Vector3D operator*(const Vector3D &other, double num)
{
    Vector3D res;
    res.vector[0] = other.vector[0] * num;
    res.vector[1] = other.vector[1] * num;
    res.vector[2] = other.vector[2] * num;
    return res;
}

/**
 * An overload to the / operator: divides each value of the given vector by the given number
 * @param other - the vector to be divided
 * @param num - the dividor
 * @return a new vector.
 */
Vector3D operator/(const Vector3D &other, double num)
{
    if (num == 0)
    {
        std::cerr << "Error - division by 0" << std::endl;
        exit(1);
    }
    else
    {
        Vector3D res;
        res.vector[0] = other.vector[0] / num;
        res.vector[1] = other.vector[1] / num;
        res.vector[2] = other.vector[2] / num;
        return res;
    }
}

/**
 * An overload to the * operator: multiplies each value of the given vactor by the given number
 * @param num - the multiplier
 * @param other - the vector to be multiplied
 * @return - a new vector
 */
Vector3D operator*(const double num, const Vector3D &other)
{
    Vector3D res;
    res.vector[0] = other.vector[0] * num;
    res.vector[1] = other.vector[1] * num;
    res.vector[2] = other.vector[2] * num;
    return res;
}

/**
 * An overload to the *= operator: multiplies each value of the current  vactor by the given number
 * @param num - the multiplier
 * @return a pointer to this vector
 */
Vector3D &Vector3D::operator*=(double num)
{
    *this = num * (*this);
    return *this;
}

/**
 * An overload to the /= operator: divides each value of the current  vactor by the given number
 * @param num - the multiplier
 * @return a pointer to this vector
 */
Vector3D &Vector3D::operator/=(double num)
{
    *this = *this / num;
    return *this;
}

/**
 * An overload of the | operator: returns the distance between 2 vectors.
 * @param other - the other vector to get distance from
 * @return a double representing the distance
 */
const double Vector3D::operator|(Vector3D &other)
{
    double d1 = pow(this->vector[0] - other.vector[0], 2);
    double d2 = pow(this->vector[1] - other.vector[1], 2);
    double d3 = pow(this->vector[2] - other.vector[2], 2);
    double sum = d1 + d2 + d3;
    return sqrt(sum);
}

/**
 * An overload of the * operator: multiplies 2 vectors
 * @param other - the vector to be multiplied
 * @return a double representing the result
 */
const double Vector3D::operator*(Vector3D &other)
{
    double d1 = this->vector[0] * other.vector[0];
    double d2 = this->vector[1] * other.vector[1];
    double d3 = this->vector[2] * other.vector[2];
    return d1 + d2 + d3;
}

/**
 * An overload of the ^ operator: calculates the radian angle of this vector.
 * @param other - the vector to calculate
 * @return a double representing the angle.
 */
const double Vector3D::operator^(Vector3D &other)
{
    double scalar = (*this) * other;
    double norm = ((*this).norm()) * (other.norm());
    return acos(scalar / norm);
}

/**
 * An overloading of the = operator: a shallow copy
 * @param other - the vector to be copied from
 * @return the pointer to this vector.
 */
Vector3D &Vector3D::operator=(const Vector3D &other)
{
    this->vector[0] = other.vector[0];
    this->vector[1] = other.vector[1];
    this->vector[2] = other.vector[2];
    return *this;
}

/**
 * An overload to the [] operator.
 * @param index
 * @return the value of the vector in the index location
 */
const double Vector3D::operator[](int index) const
{
    if (index > 2 || index < 0)
    {
        cerr << "Error - out of range";
        exit(1);
    }
    return this->vector[index];
}

/**
 * An overload to the [] operators: allowing changing the values of the vector the index location
 * @param index
 * @return a reference to the desired value
 */
double &Vector3D::operator[](int index)
{
    if (index > 2 || index < 0)
    {
        cerr << "Error - out of range";
        exit(1);
    }
    return this->vector[index];
}
//---------------------------------- additional functions ----------------------------------//
/**
* A function calculating the 2nd norm of the given vector
* @return a double representing the norm
*/
const double Vector3D::norm()
{
    Vector3D zero;
    return (*this) | zero;
}

/**
 * This function calculates the distance between 2 vectors.
 * @param other - the vector to calculate the distance from.
 * @return a double representing the distance
 */
const double Vector3D::dist(Vector3D &other)
{
    return (*this) | other;
}