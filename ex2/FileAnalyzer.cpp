//
// Created by אלה on 25/12/2018.
//

#include "FileAnalyzer.h"
#include <boost/tokenizer.hpp>
#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <cmath>
#include <numeric>
#define DELIMITERS "\", !:;"

using namespace std;
using namespace boost::algorithm;

/**
 * A constructor for the FileAnalyzer class. receives a file name and a vector of frequent words
 * and analyzes the text in the file accordingly.
 * @param file - a string representing the path for the file to be analyzed.
 * @param freqWords - a vector containing all the frequent words.
 */
FileAnalyzer::FileAnalyzer(string &file, const vector<string> &freqWords)
{
    _generateWordMap(freqWords);
    _analyze(file);
    _generateScoreVector();

}

/**
 * This function generates an STL map object containing the frequent words as keys and 0 as the value.
 * @param words - a vector containing all the frequent words.
 * @return this pointer
 */
FileAnalyzer &FileAnalyzer::_generateWordMap(const vector<string> &words)
{
    for (auto &word : words)
    {
        _scoreMap[word] = 0;
    }
    return *this;
}

/**
 * This function analyzes the given file and inserts to the map the count of times they appeared in the file.
 * @param file - a string representing the path for the file to be analyzed.
 * @return this pointer.
 */
FileAnalyzer &FileAnalyzer::_analyze(string &file)
{
    typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
    boost::char_separator<char> sep{DELIMITERS};
    ifstream inFile{file};
    if (!inFile.is_open())
    {
        return *this;
    }
    string line;
    // converting each line into a string and tokenizing it.
    while (getline(inFile, line))
    {
        line = to_lower_copy(line);
        tokenizer tok{line, sep};
        for (tokenizer::iterator it = tok.begin(); it != tok.end(); ++it)
        {
            if (_scoreMap.find(*it) != _scoreMap.end())
            {
                _scoreMap[*it]++;
            }
        }
    }
    return *this;
}

/**
 * This function creates a vector of all the word counts from the map.
 * @return this pointer.
 */
FileAnalyzer &FileAnalyzer::_generateScoreVector()
{
    for (auto &it : _scoreMap)
    {
        _scoreVector.push_back(it.second);
    }
    return *this;
}

/**
 * This function calculates and returns the norm of the word count vector.
 * @return the norm of this vector.
 */
double FileAnalyzer::getNorm() const
{
    double res = 0;
    for (int i : _scoreVector)
    {
        res += i * i;
    }
    return sqrt(res);
}

/**
 * An overloading function of the "*" operator - allowing the program to easily multiply two
 * FileAnalyzer objects to get the value of the scoreVector multipication.
 * @param other - the second FileAnalyzer
 * @return a double representing the multipication.
 */
double FileAnalyzer::operator*(FileAnalyzer &other)
{
    return inner_product(std::begin(_scoreVector), std::end(_scoreVector), std::begin(other._scoreVector), 0.0);
}


