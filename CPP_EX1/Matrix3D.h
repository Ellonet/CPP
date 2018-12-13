//
// Created by אלה on 10/12/2018.
//

#ifndef CPP_EX1_MATRIX3D_H
#define CPP_EX1_MATRIX3D_H

#include <stdlib.h>
#include <iostream>
#include "Vector3D.h"
using namespace std;

class Matrix3D {
private:
    void init (Vector3D v1, Vector3D v2, Vector3D v3);
    Vector3D v1;
    Vector3D v2;
    Vector3D v3;

public:
    Matrix3D();
    explicit Matrix3D(double num);
    Matrix3D(int num1, int num2, int num3, int num4, int num5, int num6, int num7, int num8, int num9);
    explicit Matrix3D(double (&arr)[9]);
    explicit Matrix3D(double (&arr)[3][3]);
    Matrix3D(Vector3D v1, Vector3D v2, Vector3D v3);
    Matrix3D(const Matrix3D &other);
    friend ostream& operator<<(ostream &out, const Matrix3D& matrix);
    friend istream& operator>>(istream &in, Matrix3D& matrix);
    Matrix3D& operator-=(Matrix3D &other);
    Matrix3D& operator+=(Matrix3D &other);
    Matrix3D& operator*=(Matrix3D &other);
    Matrix3D operator+(Matrix3D &other);
    Matrix3D operator-(Matrix3D &other);
    Matrix3D operator*(Matrix3D &other);
    Matrix3D& operator*=(double num);
    Matrix3D& operator/=(double num);
    Vector3D operator*(Vector3D &vector);
    Matrix3D& operator=(const Matrix3D &other);
    Vector3D operator[](int index) const;
    Vector3D &operator[](int index);
    Vector3D row(int index);
    Vector3D column(int index);
    double trace();
    double determinant();

};

#endif //CPP_EX1_MATRIX3D_H
