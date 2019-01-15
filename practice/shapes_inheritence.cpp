//
// Created by ellonet on 1/15/19.
//


#include <iostream>

using namespace std;

class shape {
public:
    virtual void draw() = 0;
//    {
//        cout << "Im a generic shape" << endl;
//    }
    virtual ~shape() = default;
};


class circle : public shape { int c;
    void draw() override {
        cout << "Im a circle" << endl;
    }

    void bla() {
        cout << "in unique!" << endl;
    }

};

class square final : public shape {
    void draw() override {
        cout << "Im a square" << endl;
    }
};


//class shit : public square {}; // doesnt compile



class base{
public:
    int a = 1;
    int b = 2;
};

class der : public base {
public:
    int a = 3;
    int b = 3;
    int c = 3;
};