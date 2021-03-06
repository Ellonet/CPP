//
// Created by אלה on 09/01/2019.
//
#include "Complex.h"
#include "Matrix.hpp"
#include <chrono>
#include <iostream>
#include <stack>
#include "eigen3/Eigen/Dense"
//#include <Eigen/Dense>

using namespace std;

stack<chrono::time_point<chrono::system_clock>> tictoc_stack;

/**
 * This function is used to time the performences of other functions.
 */
void toc()
{
    chrono::duration<double> elapsed_seconds = chrono::system_clock::now() - tictoc_stack.top();
    cout << "<" << elapsed_seconds.count() << ">\n";
    tictoc_stack.pop();
}

/**
 * This function is used to time the performences of other functions.
 */
void tic()
{
    tictoc_stack.push(chrono::system_clock::now());
}

/**
 * This main function runs the comparisam of the Eigen matrix and my matrix.
 * @param argc
 * @param argv
 * @return 0
 */
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error - not enough arguments" << endl;
        exit(1);
    }
    const unsigned int n = stoul(argv[1]);
    cout << "size<" << n << ">" << endl;
    Eigen::MatrixXd eigM1 = Eigen::MatrixXd::Random(n, n);
    Eigen::MatrixXd eigM2 = Eigen::MatrixXd::Random(n, n);
    vector<int> v(n * n, 1);
    Matrix<int> myM1 = Matrix<int>(n, n, v);

    tic();
    eigM1 * eigM2;
    cout << "eigen mult ";
    toc();
    tic();
    eigM1 + eigM2;
    cout << "eigen add ";
    toc();
    tic();
    myM1 * myM1;
    cout << "matlib mult ";
    toc();
    tic();
    eigM1 + eigM2;
    cout << "matlib add ";
    toc();
    return 0;
}
