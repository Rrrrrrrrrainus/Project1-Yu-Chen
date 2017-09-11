// include all needed libriaries and .h files
#include "checker.h"
#include "NewString.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

//constructor
Checker::Checker(){

}

// constructor which passes three files' name and call the functions to check misspelled words
Checker::Checker(const char* fileDictionary,const char* fileManuscript,const char* fileOutput){

    // run functions to do all steps and output incorrect words
    readWords(fileDictionary,fileManuscript,fileOutput);
}

// function to read words in dictionary
void Checker::readDictionary(const char* fileDictionary){
    // open the dictionary file
    fileIn2.open(fileDictionary);

    // read the number of words in dictionary in the first line
    int wordsNumber = 0;
    fileIn2>>wordsNumber;

    // initialize a cstring
    char* dicWord = new char[80];

    // read the word from dictionary
   for(int i =0; i< wordsNumber; i++){

    fileIn2>>dicWord;
    dictionaryWord = dicWord;

    // add words into vector
    dictionaries.push_back(dictionaryWord);



}

   // close file
    fileIn2.close();
}

// function to check words, if its right, return 1, otherwise return 0
int Checker::checkWords(){
    // set return number to 0
    int checkAnswer = 0;
    // use for loop to compare word with words in dictionary
    for(int i = 0; i< dictionaries.size(); i++){
        if(readWord == dictionaries[i]){
            // if its right, return 1
            checkAnswer = 1;
        }
    }
    // else return 0
    return checkAnswer;
}

// fuction to pass the wrong word and give the suggestion
String Checker::suggestion(){
    // initialize number of suggestions
    int numSuggest = 0;
    String suggest1;
    String suggest2;
    String suggest3;

    //  first suggestion
    for(int i = 0; i< dictionaries.size(); i++){

        if(numSuggest ==1)
            break;

        // if the first character equals, get the word
        if(dictionaries[i][0] == readWord[0]){

            suggest1 = dictionaries[i] + " ";
            numSuggest++;
        }
    }

    //second suggestion
    for(int i = 0; i< dictionaries.size(); i++){

        if(numSuggest ==2)
            break;

        // if the middle character equals, get the word
        if(dictionaries[i][dictionaries[i].size()/2] == readWord[readWord.size()/2]){
            suggest2 = dictionaries[i] + " ";
            numSuggest++;
            }

    }

    //third suggestion
    for(int i = 0; i< dictionaries.size(); i++){

        if(numSuggest ==3)
            break;

        // if the last character equals, get the word
        if(dictionaries[i][dictionaries[i].size()-1] == readWord[readWord.size()-1]){
            suggest3 = dictionaries[i] + " ";
            numSuggest++;
        }

    }


    // return three suggestions
    return suggest1+suggest2+suggest3;
}

// function to output incorrect word and its position and suggestion
void Checker::outputWords(int lineNum, int indexNum){

    // output information to file
    fileOut<< readWord << "  <"<< lineNum<<", "<<indexNum<<">  "  << ". Are you looking for :"<< suggestion()<<endl;

}

// fuction to read the word and check whether it's correct or not
void Checker::readWords(const char* fileDictionary, const char* fileManuscript, const char* fileOutput){
    // set postion to 0
    line = 0;
    index = 0;

    //open manuscript file and output file
    fileIn.open(fileManuscript, ios::in);
    fileOut.open(fileOutput);

    // if file not open, exit
    if(!fileIn){
        exit(EXIT_FAILURE);
    }

    // read word from dictionary
    readDictionary(fileDictionary);

    //initialize a cstring with max char 80, get the whole line and put it into cstring
    char lineChar[80];
    fileIn.getline(lineChar,80);


    //initialize a string class with line
    String lineString(lineChar);
    lineString = lineString + " ";


    // if it is not end of file, keep reading
    while(!fileIn.eof()){
        //increment line and set index to 0
        ++line;
        index = 0;


        int position = -1;

        // for loop to get each word in a line
        for(int i = 0; i< lineString.size(); i++){

        // if it's while space, get the word in front of it
        if(lineString[i] == ' '){
                readWord = lineString.substring(position+1, i-(position+1));
                position = i;
                readWord[readWord.size()-1] = '\0';
                index++;
                // call function to check words
                if(checkWords() == 0){
                    // if word is incorrect, output it
                    outputWords(line, index);

                }
          }


        }

        // keep read next line
        fileIn.getline(lineChar,80);
        lineString = lineChar;
        lineString = lineString + " ";

    }

    // close files
    fileIn.close();
    fileOut.close();
}
