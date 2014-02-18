/**
 *  implements functionality of Document
 *
 * @author 		Bethany Armitage
 * Course: 		COMS B35
 * Created: 	Feb 15, 2014
 * Source File:	Document.h
 */

#include "Document.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

	Document::Document(int initialSize ){
        numStrings = 0;
        maxStrings = initialSize;
        strings = new string* [initialSize];
    }
	Document::Document(const Document& otherDocument){
        copyDoc(otherDocument);
    }
	Document::~Document(){
        deleteStrings();
    }
    // overloading assignment(=) operator
	const Document& Document::operator=(const Document& otherDocument){
        copyDoc(otherDocument);
        return *this;
    }
	bool Document::addString(string str){
        if( numStrings < maxStrings ){
            // allocate space for each individual string
            strings [numStrings] = new string[30];
            // add new value to array and increment numStrings
            *strings [numStrings++] = str;
            return true;
        }
        return false;
    }
    //get specific string at index
	string Document::getStringAt(int index) {
        if( index >= numStrings){
            cerr << "Invalid index:"<< index << endl;
            exit(1);
        }
        return *strings[index];
    }
	void Document::printDocument(){
        // print address of strings**
        cout << strings << endl;
        for (int i=0; i < numStrings; i++){
            // print each string in strings** followed by its address
            cout << *strings[i] << " (" << strings[i] << ")" << endl;
        }
    }
	void Document::copyDoc(const Document& otherDocument){
        //copy over member variables
        numStrings = otherDocument.numStrings;
        maxStrings = otherDocument.maxStrings;
        for(int i=0; i < numStrings; i++){
            strings[i] = otherDocument.strings[i];
        }
        return;
    }
	void Document::deleteStrings(){
        for(int i=0; i < numStrings; i++){
            delete [] strings[i];
            strings[i] = NULL;
        }
        delete [] strings;
            //delete strings;
        return;
    }
