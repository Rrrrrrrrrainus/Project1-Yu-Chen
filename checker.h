// class checher to check misspelled words and output into a file
#ifndef CHECKER_H
#define CHECKER_H
// incluse string class
#include "NewString.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

//class checker
class Checker{

    private:
        // two integers to get the postion of misspelled word
        int index;
        int line;

        // ifstream and ofstream objects to input and out words
        ifstream fileIn;
        ifstream fileIn2;
        ofstream fileOut;
        vector<String> dictionaries;

        String readWord;
        String dictionaryWord;

    public:\
        //constructors
        Checker();
        Checker(const char*,const char*,const char*);

        // functions to read, check, suggest and output words
        void readDictionary(const char*);
        int checkWords();
        String suggestion();
        void outputWords(int, int);
        void readWords(const char*,  const char*, const char*);

};
#endif // CHECKER_H
