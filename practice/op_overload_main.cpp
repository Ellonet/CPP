#include <iostream>
#include "op_overload.cpp"


using namespace std;



int main() {

    Yo me("Ella", 26);
    Yo f1("friend1", 20);
    Yo f2("friend2", 29);
    cout << (f1<me);

    me += f1;
    me += f2;
    cout << me;

    return 0;
}