//
// Created by אלה on 08/12/2018.
//
#include <iostream>
#include <math.h>
#include <string>
#include "Vector3D.h"
using namespace std;


///////////// constructors /////////////
void Vector3D::init(double v1, double v2, double v3) {
    this->vector[0] = v1;
    this->vector[1] = v2;
    this->vector[2] = v3;
}

Vector3D::Vector3D() {
    init(0, 0, 0);
}

Vector3D::Vector3D(double d1, double d2, double d3) {
    init(d1, d2, d3);
}

Vector3D::Vector3D(double (&arr)[3]) {
    init(arr[0], arr[1], arr[2]);
}

Vector3D::Vector3D(const Vector3D &other) {
    double d1 = other.vector[0];
    double d2 = other.vector[1];
    double d3 = other.vector[2];
    init(d1, d2, d3);
}

///////////// streams overloading /////////////
ostream &operator<<(ostream &outStream, const Vector3D &other) {
    return outStream << other.vector[0] << " " << other.vector[1] << " " << other.vector[2];
}

istream &operator>>(istream &inStream, Vector3D &vector) {
    inStream >> vector.vector[0];
    inStream >> vector.vector[1];
    inStream >> vector.vector[2];
    return inStream;
}


///////////// operators overloading /////////////
const Vector3D Vector3D::operator+(const Vector3D &other) {
    Vector3D res;
    res.vector[0] = this->vector[0] + other.vector[0];
    res.vector[1] = this->vector[1] + other.vector[1];
    res.vector[2] = this->vector[2] + other.vector[2];
    return res;
}

const Vector3D Vector3D::operator-(const Vector3D &other) {
    Vector3D res;
    res.vector[0] = this->vector[0] - other.vector[0];
    res.vector[1] = this->vector[1] - other.vector[1];
    res.vector[2] = this->vector[2] - other.vector[2];
    return res;
}

Vector3D &Vector3D::operator+=(const Vector3D &other) {
    *this = *this + other;
    return *this;
}

Vector3D &Vector3D::operator+=(double num) {
    this->vector[0] += num;
    this->vector[1] += num;
    this->vector[2] += num;
    return *this;
}

Vector3D &Vector3D::operator-=(const Vector3D &other) {
    *this = *this - other;
    return *this;
}

Vector3D &Vector3D::operator-=(double num) {
    this->vector[0] -= num;
    this->vector[1] -= num;
    this->vector[2] -= num;
    return *this;
}

Vector3D operator-(const Vector3D &vector) {
    Vector3D zero;
    return zero - vector;
}

Vector3D operator*(const Vector3D &other, double num) {
    Vector3D res;
    res.vector[0] = other.vector[0] * num;
    res.vector[1] = other.vector[1] * num;
    res.vector[2] = other.vector[2] * num;
    return res;
}

Vector3D operator/(const Vector3D &other, double num) {
    if (num == 0) {
        std::cerr << "Error - division by 0" << std::endl;
        exit(1);
    } else {
        Vector3D res;
        res.vector[0] = other.vector[0] / num;
        res.vector[1] = other.vector[1] / num;
        res.vector[2] = other.vector[2] / num;
        return res;
    }
}

Vector3D operator*(const double num, const Vector3D &other) {
    Vector3D res;
    res.vector[0] = other.vector[0] * num;
    res.vector[1] = other.vector[1] * num;
    res.vector[2] = other.vector[2] * num;
    return res;
}

Vector3D &Vector3D::operator*=(double num) {
    *this = num * (*this);
    return *this;
}

Vector3D &Vector3D::operator/=(double num) {
    *this = *this / num;
    return *this;
}

const double Vector3D::operator|(Vector3D &other) {
    double d1 = pow(this->vector[0] - other.vector[0], 2);
    double d2 = pow(this->vector[1] - other.vector[1], 2);
    double d3 = pow(this->vector[2] - other.vector[2], 2);
    double sum = d1 + d2 + d3;
    return sqrt(sum);
}

const double Vector3D::operator*(Vector3D &other) {
    double d1 = this->vector[0] * other.vector[0];
    double d2 = this->vector[1] * other.vector[1];
    double d3 = this->vector[2] * other.vector[2];
    return d1 + d2 + d3;
}

const double Vector3D::norm() {
    Vector3D zero;
    return (*this) | zero;
}

const double Vector3D::operator^(Vector3D &other) {
    double scalar = (*this) * other;
    double norm = ((*this).norm()) * (other.norm());
    return acos(scalar / norm);
}

Vector3D &Vector3D::operator=(const Vector3D &other) {
    this->vector[0] = other.vector[0];
    this->vector[1] = other.vector[1];
    this->vector[2] = other.vector[2];
    return *this;
}

const double Vector3D::operator[](int index) const {
    if (index > 2 || index < 0) {
        cerr << "Error - out of range";
        exit(1);
    }
    return this->vector[index];
}

double &Vector3D::operator[](int index) {
    if (index > 2 || index < 0) {
        cerr << "Error - out of range";
        exit(1);
    }
    return this->vector[index];
}

const double Vector3D::dist(Vector3D &other) {
    return (*this) | other;
}




