

/**
* This program creates the implementation for Lexicon.h
*
* @author Bethany Armitage
* Course: Comsb25
* Created:  Wed 01/29/2014 
* Source File: Lexicon.cpp
*/

#include "Lexicon.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

//constructor
Lexicon::Lexicon( string lexiconFileName){
    Lexicon::loadLexicon(lexiconFileName);
}

void Lexicon::loadLexicon( string lexiconFileName){
    ifstream in;
    string word;
    std::vector<string>::iterator it;
    
    //string needs to be converted to char *ptr for open function
    in.open(lexiconFileName.c_str());
    if( in.fail() ){
        cerr << "could not open file\n";
        exit( 1 );
    }
    
    else{ //add each word to vector lexicon
        while(in >> word)
        Lexicon::lexicon.push_back(word);
    }
}

bool Lexicon::isWord(string word){
    // iterate vector linearly to check for match
    vector<string>::iterator it;
    string tmp;

    for(it = lexicon.begin(); it < lexicon.end(); it++){
        tmp = *it;
        if( tmp.compare( word ) == 0 ){

            return true;
        }
    }
    return false;
    
}
