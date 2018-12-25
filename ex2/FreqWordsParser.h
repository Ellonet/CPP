#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

#ifndef EX2_FREQWORDPARSER_H
#define EX2_FREQWORDPARSER_H

class FreqWordPaeser {
public:
    explicit FreqWordPaeser(string &fileName);
    vector<string> getFreqWords() const;

private:
    vector<string> _allWords;
    ifstream _file;
    FreqWordPaeser& readInput(string &filename);
};

#endif //EX2_FREQWORDPARSER_H
