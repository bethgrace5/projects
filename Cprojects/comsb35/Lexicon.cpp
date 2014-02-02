
/**
* This program creates the implementation for Lexicon.h
*
* @author Bethany Armitage
* Course: Comsb25
* Created:  Wed 01/29/2014 
* Source File: Lexicon.cpp
*/

#include "Lexicon.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

//constructor
Lexicon::Lexicon( string lexiconFileName){
    Lexicon::loadLexicon(lexiconFileName);
}

Lexicon::loadLexicon( string lexiconFileName){
    ifstream in;
    std::vector<string>::iterator it;
    
    //string needs to be converted to char *ptr
    in.open(lexiconFileName.c_str());
    
    while(in << word)
        Lexicon::lexicon.add(word);

}

Lexicon::isWord(string word){
    //iterate through Lexicon::lexicon vector
    
}

