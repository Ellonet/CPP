//
// Created by ellonet on 1/15/19.
//

#include "diamond_inh.cpp"

using namespace std;



int main () {
    person f1("person f1", 20);
    programmer f2("prog f1", 20, "bla");

    person p1("p1", 20);
    p1 += f1;
    programmer prog("prog1", 25, "aroma");
    prog += f2;

    student s("ella", 28, "huji");
    student noone("None", 10, "huji");
    s+= noone;

    work_and_learn omg("Ella", 28, "cyberMDX", "huji");

    cout << p1;
    cout << prog;
    cout << s;
    cout << omg;




    return 0;
}