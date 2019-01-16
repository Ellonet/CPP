//
// Created by ellonet on 1/16/19.
//


#include <iostream>

using namespace std;



class electric_part {
public:
    electric_part(double p) : _price(p) {}

    virtual double getPrice() const
    {
        return _price;
    };

    virtual void print() const = 0;

protected:
    double _price;
};


class button : virtual public electric_part {
public:
    button() : electric_part(2) {}
    void print(void) const override {
        cout << "button: " << getPrice() << endl;
    }

};

class light_bulb : virtual public electric_part {
public:
    light_bulb() : electric_part(3.5) {}
    void print(void) const override {
        cout << "light bulb: " << getPrice() << endl;
    }
};

class desk_lamp : public button, public light_bulb {
public:
//    desk_lamp() : electric_part(6), button(), light_bulb() {}
    desk_lamp() : electric_part(6), button(), light_bulb() {}
    void print(void) const {
        cout << "desk lamp: " << getPrice() << endl;
    }
};
//
//
//int main () {
//    const button b;
//    b.print();
//    const light_bulb lb;
//    lb.print();
//    const desk_lamp dl;
//    dl.print();
//
//}
//
//
