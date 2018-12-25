#include <iostream>
#include <string>
#include <vector>
#include "FreqWordsParser.h"

#include <boost/tokenizer.hpp>
using namespace std;

int main(int argc, char** argv) {
//    typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
//    std::string s = "Boost C++ Libraries";
//    boost::char_separator<char> sep{" ,."};
//    tokenizer tok{s, sep};
//    for (tokenizer::iterator it = tok.begin(); it != tok.end(); ++it)
//        std::cout << *it << '\n';

    // reading the input
    string freqWordFile = argv[1];
    string unknown = argv[2];
    vector<string> textFilesNames;
    for (int i=3; i<argc; i++) {
        textFilesNames.emplace_back(argv[i]);
    }

    // generatr wordlist vector
    FreqWordPaeser freqWords(freqWordFile);
    vector<string> freqWordList = freqWords.getFreqWords();
    for (auto &i : freqWordList) {
        cout << i << "\n";
    }


    return 0;
}