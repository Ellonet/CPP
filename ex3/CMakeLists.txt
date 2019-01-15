cmake_minimum_required(VERSION 3.12)
project(ex3)

set(CMAKE_CXX_STANDARD 14)

add_executable(ex3 Matrix.hpp Complex.cpp Complex.h tester.cpp)
#add_executable(ex3 Matrix.hpp Complex.cpp Complex.h exceptionTesterEx3.cpp)
#add_executable(ex3 Matrix.hpp Complex.cpp Complex.h TimeChecker.cpp)
