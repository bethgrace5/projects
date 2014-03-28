/**
* This program creates the implementation for LexiconLazyBinarySearch.h
*
* @author       Bethany Armitage
* Course:       Comsb35
* Created:      Thu 03/27/2014 
* Source File:  LexiconLazyBinarySearch.cpp
*/

#include "LexiconLazyBinarySearch.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

//constructor
LexiconLazyBinarySearch::LexiconLazyBinarySearch( string lexiconFileName){
    LexiconLazyBinarySearch::loadLexicon(lexiconFileName);
}

void LexiconLazyBinarySearch::loadLexicon( string lexiconFileName){
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
        LexiconLazyBinarySearch::lexicon.push_back(word);
    }
}

bool LexiconLazyBinarySearch::isWord(string word){

    int first = 0;
    int last  = lexicon.size() - 1;
    int mid;

    while (first < last)
    {
        mid = (first + last) / 2;

        if (lexicon[mid] < word) // move first above middle 
            first = mid + 1;

        else  // move last to middle 
            last = mid;
    }

    if(lexicon[last] == word)
        return true;
    else
        return false;

} //end LexiconLazyBinarySearch
    
