//
// Created by אלה on 25/12/2018.
//

#include "FreqWordsParser.h"

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
        _allWords.push_back(text);
    }
    return *this;
}

