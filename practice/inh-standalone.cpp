
#include <iostream>

using namespace std;


struct A {
    virtual void f() { cout << "A::f()" << endl; }
};

struct B1 : virtual A {
    void f() override { cout << "B1::f()" << endl; }
};

struct B2 : virtual A {
    void f() override { cout << "B1::f()" << endl; }
};

struct C : B1, B2 {
    void f() override {cout << "C::f()" << endl; }
};

int main() {
    C c;
    c.f();
    c.A::f();
    c.B1::f();
    c.B2::f();

    return 0;
}