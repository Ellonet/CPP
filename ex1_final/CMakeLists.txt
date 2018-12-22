cmake_minimum_required(VERSION 3.12)
project(ex1_final)

set(CMAKE_CXX_STANDARD 14)

#add_executable(ex1_final ex1.cpp Matrix3D.cpp Vector3D.cpp)
add_executable(ex1_final tester.cpp Matrix3D.cpp Vector3D.cpp)