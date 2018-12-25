#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "FreqWordsParser.h"
#include "FileAnalyzer.h"

using namespace std;

int main(int argc, char** argv) {

    // reading the input
    string freqWordFile = argv[1];
    string unknown = argv[2];

    // generating word list vector
    FreqWordPaeser freqWords(freqWordFile);
    const vector<string> freqWordList = freqWords.getFreqWords();

    // get score of unknown file:
    FileAnalyzer unknownFileVector(unknown, freqWordList);

    // compare all vectors:
    double bestScore = 0;
    double score;
    string bestMatch;
    for (int i=3; i<argc; i++) {
        string tempName = argv[i];
        FileAnalyzer temp(tempName, freqWordList);
        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(3);
        score = (unknownFileVector*temp)/(unknownFileVector.getNorm()*temp.getNorm());
        cout << tempName << " " << score << endl;
        if (score > bestScore) {
            bestScore = score;
            bestMatch = tempName;
        }
    }

    cout << "Best matching author is " << bestMatch << " score " << bestScore << endl;
    return 0;
}