//
// Created by ellonet on 1/15/19.
//
#include <iostream>
#include "inheritece.cpp"
#include "shapes_inheritence.cpp"

using namespace std;


int main() {
// ------------- regular inheritence ------------- //
//    person me("Ella", 28);
//    person you("friend1", 25);
//    person you2("friend2", 25);
//    me += you;
//    cout << me;
//    cout << "feeling " << me.getMood() << endl;
//    programmer new_me("Ella", 28, "Cyber");
//    new_me += you2;
//    cout << new_me;
//    cout << "feeling " << new_me.getMood() << endl;
//    person *p = &new_me;
//    cout << p->getMood();


// ------------- regular inheritence ------------- //
//    shape *my_shapes[3] = {new circle, new square, new shape}; // will not work cuz made shape virtual
//    shape *my_shapes[2] = {new circle, new square};
//
//    for(auto &i : my_shapes) {
//        i->shape::draw();
//        cout << "of type: ";
//        i->draw();
//        cout << endl;
//    }
//
//    for(auto &i : my_shapes) {
//        delete i;
//    }


//    shape *p = new square;
//    p->draw();
//    p->bla(); //  doesnt compile

// ------------- casting ------------- //

    base b;
    der d;
    b = d;

    cout << b.a;
    cout << b.b;

        //    cout << b.c;


    return 0;
}