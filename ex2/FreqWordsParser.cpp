//
// Created by אלה on 25/12/2018.
//
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include "FreqWordsParser.h"

using namespace std;
using namespace boost::algorithm;


FreqWordPaeser::FreqWordPaeser(string &fileName) {
    readInput(fileName);
}


vector<string> FreqWordPaeser::getFreqWords() const {
    return _allWords;
}

FreqWordPaeser &FreqWordPaeser::readInput(string &filename) {
    string text;
    ifstream inFile{filename};
    while (inFile >> text) {
        text = to_lower_copy(text);
        _allWords.push_back(text);
    }
    return *this;
}

