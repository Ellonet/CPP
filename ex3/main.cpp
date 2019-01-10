#include <iostream>
#include "Matrix.hpp"
#include "Complex.h"


using namespace std;

int main()
{

    vector<int> bla2 = {1, 2, 3, 4, 5, 6, 7,8,9};
    Matrix<int> bla(3, 3, bla2);
    Matrix<int>::const_iterator = bla.begin();


    return 0;
}