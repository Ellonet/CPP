//
// Created by אלה on 25/12/2018.
//
#ifndef EX2_FILEANALYZER_H
#define EX2_FILEANALYZER_H

#include <vector>
#include <map>
#include <string>

using namespace std;

/**
 * This class represents a FileAnalyzer - which receives a path to a file and
 * analyzes and grades it according to the given list of grequent words.
 */
class FileAnalyzer
{
public:
    /**
    * A constructor for the FileAnalyzer class. receives a file name and a vector of frequent words
    * and analyzes the text in the file accordingly.
    * @param file - a string representing the path for the file to be analyzed.
    * @param freqWords - a vector containing all the frequent words.
    */
    explicit FileAnalyzer(string &file, const vector<string> &freqWords);

    /**
     * This function calculates and returns the norm of the word count vector.
     * @return the norm of this vector.
     */
    double getNorm() const;

    /**
     * An overloading function of the "*" operator - allowing the program to easily multiply two
     * FileAnalyzer objects to get the value of the scoreVector multipication.
     * @param other - the second FileAnalyzer
     * @return a double representing the multipication.
     */
    double operator*(FileAnalyzer &other);


private:
    /**
     * A map representing the score map - the keys are the frequent words and the values are how many times they
     * appeared in the file.
     */
    map<string, int> _scoreMap;
    /**
     * A vector representing all the word counts for each frequent word.
     */
    vector<int> _scoreVector;

    /**
     * This function generates an STL map object containing the frequent words as keys and 0 as the value.
     * @param words - a vector containing all the frequent words.
     * @return this pointer
     */
    FileAnalyzer &_generateWordMap(const vector<string> &words);

    /**
     * This function creates a vector of all the word counts from the map.
     * @return this pointer.
     */
    FileAnalyzer &_generateScoreVector();

    /**
     * This function analyzes the given file and inserts to the map the count of times they appeared in the file.
     * @param file - a string representing the path for the file to be analyzed.
     * @return this pointer.
     */
    FileAnalyzer &_analyze(string &file);

};

#endif //EX2_FILEANALYZER_H
