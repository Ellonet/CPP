#include<iostream>
#include "classBase.h"

using namespace std;

class Derived : public Base
{
public:
    Derived()
    {
        cout << 5;
    }
    ~Derived()
    {
        cout << 23;

    }

};

int main()

{

    Base *basePtr =new Derived();

    delete basePtr;

    return 0;

}
