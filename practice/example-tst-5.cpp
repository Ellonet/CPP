//
// Created by אלה on 16/01/2019.
//

#include <iostream>

class Shape
{
public:
    virtual double area() const = 0;
    virtual double circumference() const = 0;
protected:
    double xCenter;
    double yCenter;
};


class Circle : public Shape {
public:
    Circle (double x, double y, double r) {
        xCenter = x;
        yCenter = y;
        _radius = r;
    }
    double area() const {
        return 3*_radius*_radius;
    }
    double circumference() const {
        return 2*3*_radius;
    }

private:
    double _radius;
};

class Square : public Shape {
public:
    Square (double x, double y, double side) {
        xCenter = x;
        yCenter = y;
        _sideLength = side;
    }
    double area() const {
        return _sideLength*_sideLength;
    }
    double circumference() const {
        return 4 * _sideLength;
    }
private:
    double _sideLength;
};

class Rectangle : public Shape {
public:
    Rectangle (double x, double y, double h, double w) {
        xCenter = x;
        yCenter = y;
        _height = h;
        _weight = w;
    }
    double area() const {
        return _height*_weight;
    }
    double circumference() const {
        return 2 * (_weight+_height);
    }
private:
    double _height;
    double _weight;
};