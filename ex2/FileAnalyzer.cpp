//
// Created by אלה on 25/12/2018.
//

#include "FileAnalyzer.h"
#include <boost/tokenizer.hpp>
#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <cmath>

using namespace std;
using namespace boost::algorithm;


FileAnalyzer::FileAnalyzer(string &file, const vector<string> &freqWords) {
    generateWordMap(freqWords);
    analyze(file);
    generateScoreVector();

}

FileAnalyzer &FileAnalyzer::generateWordMap(const vector<string> &words) {
    for (auto &word : words) {
        _scoreMap[word] = 0;
    }
    return *this;
}


FileAnalyzer &FileAnalyzer::analyze(string &file) {
    typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
    boost::char_separator<char> sep{" !?,.:;\t\n"};

    ifstream inFile{file};
    string line;

    while (getline(inFile, line)) {
        line = to_lower_copy(line);
        tokenizer tok{line, sep};
        for (tokenizer::iterator it = tok.begin(); it != tok.end(); ++it) {
            if (_scoreMap.find(*it) != _scoreMap.end()) {
                _scoreMap[*it]++;
            }
        }
    }
    return *this;
}


FileAnalyzer &FileAnalyzer::generateScoreVector() {
    for (auto &it : _scoreMap) {
        _scoreVector.push_back(it.second);
    }
    return *this;
}

vector<int> FileAnalyzer::getScoreVector() const {
    return _scoreVector;
}

double FileAnalyzer::getNorm() const {
    double res = 0;
    for (int i : _scoreVector) {
        res += i * i;
    }
    return sqrt(res);
}

double FileAnalyzer::operator*(FileAnalyzer &other) {
    double res = 0;
    for (int i = 0; i < _scoreVector.size(); ++i) {
        res += this->_scoreVector[i] * other._scoreVector[i];
    }
    return res;
}


