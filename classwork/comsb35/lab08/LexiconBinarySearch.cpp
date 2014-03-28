/**
* This program creates the implementation for LexiconBinarySearch.h
*
* @author       Bethany Armitage
* Course:       Comsb35
* Created:      Thu 03/27/2014 
* Source File:  LexiconBinarySearch.cpp
*/

#include "LexiconBinarySearch.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

//constructor
LexiconBinarySearch::LexiconBinarySearch( string lexiconFileName){
    LexiconBinarySearch::loadLexicon(lexiconFileName);
}

void LexiconBinarySearch::loadLexicon( string lexiconFileName){
    ifstream in;
    string word;
    std::vector<string>::iterator it;
    
    //string needs to be converted to char *ptr for open function
    in.open(lexiconFileName.c_str());
    if( in.fail() ){
        cerr << "could not open file " << lexiconFileName << endl;
        exit( 1 );
    }
    
    else{ //add each word to vector lexicon
        while(in >> word)
        LexiconBinarySearch::lexicon.push_back(word);
    }
}

bool LexiconBinarySearch::isWord(string word){

    int count = 0;
    int first = 0;
    int last  = lexicon.size() - 1;
    int mid;

    bool found = false;

    while (first <= last && !found){
        mid = (first + last) / 2;

        //check mid index
        if (lexicon[mid] == word){
            count++;
            return true;
        }
        // reassign last if word is in lower half of list
        else if (lexicon[mid] > word){
            count++;
            last = mid - 1;
        }    
        // reassign first if word is in upper half of list
        else{
            count++;
            first = mid + 1;
        }

    }//end while
    return false;

} //end binarySearch
    
