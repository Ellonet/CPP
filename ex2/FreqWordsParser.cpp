//
// Created by אלה on 25/12/2018.
//
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include "FreqWordsParser.h"

using namespace std;
using namespace boost::algorithm;

/**
 * A constructor of this class - receiving the file path and and generating
 * a vector of all the words in the file.
 * @param fileName - a string representing the file path.
 */
FreqWordParser::FreqWordParser(string &fileName)
{
    _readInput(fileName);
}

/**
 * A getter - allowing other classes to get the vector representing the list of
 * frequent words.
 * @return a vector.
 */
vector<string> FreqWordParser::getFreqWords() const
{
    return _allWords;
}

/**
 * This fuction is responsible of generating the vector from all the
 * words in the frequent word file.
 * @param filename - a string representing the path of the file.
 * @return this pointer.
 */
FreqWordParser &FreqWordParser::_readInput(string &filename)
{
    string text;
    ifstream inFile
            {
                    filename
            };
    if (!inFile.is_open())
    {
        return *this;
    }
    while (inFile >> text)
    {
        text = to_lower_copy(text);
        _allWords.push_back(text);
    }
    return *this;
}

