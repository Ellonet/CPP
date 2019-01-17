//
// Created by אלה on 16/01/2019.
//
#include <iostream>
using namespace std;


class a {
public:
    a(int f) {
        cout << "converting given int" << endl;
    }

    a (bool s) {
        cout << "converting given boolean" << endl;
    }

    a(const a& other) {
        cout << "int copy c-tor" << endl;
    }

    a&operator=(const a& other) {
        cout << "in = operator" << endl;
        return *this;
    }
};

int main() {
    cout << "---------------" << endl;
    a a1 = 43;
    cout << "---------------" << endl;
    a1 = 3;
    cout << "---------------" << endl;
    a a2(true);
    cout << "---------------" << endl;
    a2 = false;


}
