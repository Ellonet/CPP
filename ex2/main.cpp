#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "FreqWordsParser.h"
#include "FileAnalyzer.h"

using namespace std;

/**
 * The main function running the program.
 * @param argc - the number of given arguments.
 * @param argv - a list of char* representing the user input.
 * @return 0
 */
int main(int argc, char **argv) {
    // printing only 3 digits of doubles.
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(3);

    // handling the given word list and unknown file:
    string freqWordFile = argv[1];
    string unknown = argv[2];

    // passing the frequent word list into a parser which returns a vector
    FreqWordParser freqWords(freqWordFile);
    const vector<string> freqWordList = freqWords.getFreqWords();

    // parsing the unknown file into a FileAnalyser object:
    FileAnalyzer unknownFileVector(unknown, freqWordList);

    // parsing the rest of the given text files into a FileAnalyser object and finding the best match:
    double bestScore = 0;
    double score;
    string bestMatch;
    for (int i = 3; i < argc; i++) {
        string tempName = argv[i];
        FileAnalyzer temp(tempName, freqWordList);
        score = (unknownFileVector * temp) / (unknownFileVector.getNorm() * temp.getNorm());
        cout << tempName << " " << score << endl;
        if (score > bestScore) {
            bestScore = score;
            bestMatch = tempName;
        }
    }
    // printing the best score:
    cout << "Best matching author is " << bestMatch << " score " << bestScore << endl;
    return 0;
}