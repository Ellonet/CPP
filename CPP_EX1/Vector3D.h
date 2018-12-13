//
// Created by אלה on 08/12/2018.
//

#ifndef CPP_EX1_VECTOR3D_H
#define CPP_EX1_VECTOR3D_H
#include <stdlib.h>
#include <iostream>
using namespace std;

class Vector3D {
private:
    void init(double v1, double v2, double v3);

public:
    double vector[3];

    Vector3D();

    Vector3D(double d1, double d2, double d3);

    Vector3D(const Vector3D &other);

    explicit Vector3D(double (&arr)[3]);

    friend ostream &operator<<(ostream &stream, const Vector3D &vector);

    friend istream &operator>>(istream &is, Vector3D &vector);

    const Vector3D operator+(const Vector3D &other);

    const Vector3D operator-(const Vector3D &other);

    Vector3D &operator+=(const Vector3D &other);

    Vector3D &operator-=(const Vector3D &other);

    Vector3D &operator+=(double num);

    Vector3D &operator-=(double num);

    friend Vector3D operator-(const Vector3D &vector);

    friend Vector3D operator/(const Vector3D &other, double num);

    friend Vector3D operator*(const Vector3D &other, double num);

    friend Vector3D operator*(double num, const Vector3D &other);

    Vector3D &operator*=(double num);

    Vector3D &operator/=(double num);

    const double operator|(Vector3D &other);

    const double operator*(Vector3D &other);

    const double norm();

    const double operator^(Vector3D &other);

    Vector3D &operator=(const Vector3D &other);

    const double operator[](int index) const;

    double &operator[](int index);

    const double dist(Vector3D &other);

};

#endif //CPP_EX1_VECTOR3D_H
