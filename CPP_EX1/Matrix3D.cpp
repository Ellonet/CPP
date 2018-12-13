//
// Created by אלה on 10/12/2018.
//

#include <iostream>
#include <stdlib.h>
#include "Matrix3D.h"
using namespace std;


void Matrix3D::init(Vector3D v1, Vector3D v2, Vector3D v3) {
    this->v1 = v1;
    this->v2 = v2;
    this->v3 = v3;
}

Matrix3D::Matrix3D() {
    Vector3D v1, v2, v3;
    init(v1, v2, v3);
}

Matrix3D::Matrix3D(double num) {
    Vector3D v1(num, 0, 0);
    Vector3D v2(0, num, 0);
    Vector3D v3(0, 0, num);
    init(v1, v2, v3);
}

Matrix3D::Matrix3D(int num1, int num2, int num3, int num4, int num5, int num6, int num7, int num8, int num9) {
    Vector3D v1(num1, num2, num3);
    Vector3D v2(num4, num5, num6);
    Vector3D v3(num7, num8, num9);
    init(v1, v2, v3);
}

Matrix3D::Matrix3D(double (&arr)[9]) {
    Vector3D v1(arr[0], arr[1], arr[2]);
    Vector3D v2(arr[3], arr[4], arr[5]);
    Vector3D v3(arr[6], arr[7], arr[8]);
    init(v1, v2, v3);
}

Matrix3D::Matrix3D(double (&arr)[3][3]) {
    Vector3D v1(arr[0][0], arr[0][1], arr[0][2]);
    Vector3D v2(arr[1][0], arr[1][1], arr[1][2]);
    Vector3D v3(arr[2][0], arr[2][1], arr[2][2]);
    init(v1, v2, v3);
}

Matrix3D::Matrix3D(Vector3D v1, Vector3D v2, Vector3D v3) {
    init(v1, v2, v3);
}

Matrix3D::Matrix3D(const Matrix3D &other) {
    Vector3D v1 = other.v1;
    Vector3D v2 = other.v2;
    Vector3D v3 = other.v3;
    init(v1, v2, v3);
}

ostream &operator<<(ostream &outStream, const Matrix3D &matrix) {
    return outStream << matrix.v1 << endl << matrix.v2 << endl << matrix.v3;
}

istream &operator>>(istream &inStream, Matrix3D &matrix) {
    inStream >> matrix.v1;
    inStream >> matrix.v2;
    inStream >> matrix.v3;
    return inStream;
}

Matrix3D &Matrix3D::operator-=(Matrix3D &other) {
    this->v1 -= other.v1;
    this->v2 -= other.v2;
    this->v3 -= other.v3;
    return *this;
}

Matrix3D &Matrix3D::operator+=(Matrix3D &other) {
    this->v1 += other.v1;
    this->v2 += other.v2;
    this->v3 += other.v3;
    return *this;
}

Matrix3D &Matrix3D::operator*=(Matrix3D &other) {
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

Matrix3D Matrix3D::operator+(Matrix3D &other) {
    Matrix3D res;
    Vector3D v1, v2, v3;
    v1 = this->v1 + other.v1;
    v2 = this->v2 + other.v2;
    v3 = this->v3 + other.v3;
    res = Matrix3D(v1, v2, v3);
    return res;
}

Matrix3D Matrix3D::operator-(Matrix3D &other) {
    Matrix3D res;
    Vector3D v1, v2, v3;
    v1 = this->v1 - other.v1;
    v2 = this->v2 - other.v2;
    v3 = this->v3 - other.v3;
    res = Matrix3D(v1, v2, v3);
    return res;
}

Matrix3D Matrix3D::operator*(Matrix3D &other) {
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

Matrix3D &Matrix3D::operator*=(double num) {
    this->v1 *= num;
    this->v2 *= num;
    this->v3 *= num;
    return *this;
}

Matrix3D &Matrix3D::operator/=(double num) {
    this->v1 /= num;
    this->v2 /= num;
    this->v3 /= num;
    return *this;
}

Vector3D Matrix3D::operator*(Vector3D &vector) {
    Vector3D res;
    res[0] = this->v1 * vector;
    res[1] = this->v2 * vector;
    res[2] = this->v3 * vector;
    return res;
}

Vector3D Matrix3D::operator[](int index) const {
    Vector3D res;
    if (index == 0) {
        res = this->v1;
    }
    else if (index == 1) {
        res = this->v2;
    }
    else if (index == 2) {
        res = this->v3;
    }
    else {
        std::cerr << "Error - out of range";
        exit(1);
    }
    return res;
}

Vector3D &Matrix3D::operator[](int index) {
    if (index == 0) {
        return this->v1;

    }
    else if (index == 1) {
        return this->v2;
    }
    else if (index == 2) {
        return this->v3;
    }
    else {
        cerr << "Error - out of range";
        exit(1);
    }
}

Matrix3D &Matrix3D::operator=(const Matrix3D &other) = default;

Vector3D Matrix3D::row(int index) {
    Vector3D res;
    if (index == 0) {
        res = this->v1;
    }
    else if (index == 1) {
        res = this->v2;
    }
    else if (index == 2) {
        res = this->v3;
    }
    else {
        cerr << "Error - out of range";
        exit(1);
    }
    return res;
}

Vector3D Matrix3D::column(int index) {
    Vector3D res;
    if (index == 0) {
        res = Vector3D(this->v1[0],this->v2[0],this->v3[0]);
    }
    else if (index == 1) {
        res = Vector3D(this->v1[1],this->v2[1],this->v3[1]);
    }
    else if (index == 2) {
        res = Vector3D(this->v1[2],this->v2[2],this->v3[2]);
    }
    else {
        cerr << "Error - out of range";
        exit(1);
    }
    return res;
}

double Matrix3D::trace() {
    return this->v1[0]+this->v2[1]+this->v3[2];
}

double Matrix3D::determinant() {
    double a,b,c,d,e,f,g,h,i;
    a = this->v1[0];
    b = this->v1[1];
    c = this->v1[2];
    d = this->v2[0];
    e = this->v2[1];
    f = this->v2[2];
    g = this->v3[0];
    h = this->v3[1];
    i = this->v3[2];
    return a*(e*i-f*h)-b*(d*i-f*g)+c*(d*h-e*g);
}


