//
// Created by אלה on 25/12/2018.
//
#ifndef EX2_FILEANALYZER_H
#define EX2_FILEANALYZER_H

#include <vector>
#include <map>
#include <string>
using namespace std;

class FileAnalyzer {
public:
    explicit FileAnalyzer(string &file, const vector<string> &freqWords);
    vector<int> getScoreVector() const;
    double getNorm() const;
    double operator*(FileAnalyzer& other);


private:
    map<string, int> _scoreMap;
    vector<int> _scoreVector;
    FileAnalyzer& generateWordMap(const vector<string> &words);
    FileAnalyzer& generateScoreVector();
    FileAnalyzer& analyze(string &file);

};

#endif //EX2_FILEANALYZER_H
