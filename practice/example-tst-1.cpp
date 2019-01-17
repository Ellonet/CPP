//
// Created by אלה on 16/01/2019.
//

#include <iostream>
#include <cmath>

using namespace std;
class Shape
{
public:
    virtual float area() const = 0;
    virtual void print() const = 0;
};

class TwoDimensional:public Shape
{
public:
    virtual float perimeter() const = 0;
};

class ThreeDimensional:public Shape
{
public:
    virtual float volume() const = 0;
};

class Circle:public TwoDimensional
{
public:
    Circle (float r):_radius (r) {}

    float area() const {
        return M_PI*_radius*_radius;
    }

    float perimeter() const {
        return 2*M_PI*_radius;
    }
    void print() const {
        cout << "Circle: radius = " << _radius << endl;
    }

private:
    float _radius;
};

class Cone:public ThreeDimensional
{
public:
    Cone (float r, float h):_radius (r), _height (h) {}
    float area() const {
        return M_PI*_radius*sqrt((_radius*_radius)+(_height*_height));
    }

    float volume() const {
        return M_PI*_radius*_radius*_height*(1.0/3.0);
    }

    void print() const {
        cout << "Cone: radius = " << _radius << ", height = " << _height << endl;

    }

    // your code here
private:
    float _radius, _height;
};

