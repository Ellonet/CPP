cmake_minimum_required(VERSION 3.12)
project(ex2)

set(CMAKE_CXX_STANDARD 14)

add_executable(ex2 ex2.cpp FreqWordsParser.cpp FreqWordsParser.h FileAnalyzer.cpp FileAnalyzer.h)