#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

#ifndef EX2_FREQWORDPARSER_H
#define EX2_FREQWORDPARSER_H

/**
 * This class represents the Frequent word parser.
 * @param fileName - a string representing the path of the file of the
 * the frequent words list.
 */
class FreqWordParser
{
public:
    /**
     * A constructor of this class - receiving the file path and and generating
     * a vector of all the words in the file.
     * @param fileName - a string representing the file path.
     */
    explicit FreqWordParser(string &fileName);

    /**
     * A getter - allowing other classes to get the vector representing the list of
     * frequent words.
     * @return a vector.
     */
    vector<string> getFreqWords() const;

private:
    /**
     * A vector representing the list of frequent words.
     */
    vector<string> _allWords;

    /**
     * This fuction is responsible of generating the vector from all the
     * words in the frequent word file.
     * @param filename - a string representing the path of the file.
     * @return this pointer.
     */
    FreqWordParser &_readInput(string &filename);
};

#endif //EX2_FREQWORDPARSER_H
