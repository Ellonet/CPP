#include <iostream>
#include "Matrix.hpp"
#include "Complex.h"


using namespace std;

int main()
{

    vector<int> bla2 = {1, 2, 3, 4, 5, 6, 7,8,9};
    Matrix<int> bla(3, 3, bla2);

    Complex c1(1,1);
    Complex c2(1,2);
    Complex c3(1,3);
    Complex c4(1,4);


    vector<Complex> ccc = {c1,c2,c3,c4};
    Matrix<Complex> lala (2,2,ccc);
    cout << lala;
    cout << lala.trans();

    return 0;
}