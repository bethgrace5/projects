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
	const Document& Document::operator=(const Document& otherDocument){
        copyDoc(otherDocument);
        return *this;
    }
	bool Document::addString(string str){
        if( numStrings < maxStrings ){
                strings [numStrings] = new string[30];
                *strings [numStrings++] = str;
                return true;
        }
        return false;
    }
	string Document::getStringAt(int index)  {
        if( index >= numStrings){
            cerr << "Invalid index!" << endl;
            exit(1);
        }
        return *strings[index];
    }
	void Document::printDocument(){
        cout << strings << endl;
        for (int i=0; i < numStrings; i++){
            cout << *strings[i] << " (" << strings[i] << ")" << endl;
        }
    }
	void Document::copyDoc(const Document& otherDocument){
        numStrings = otherDocument.numStrings;
        maxStrings = otherDocument.maxStrings;
        for(int i=0; i < numStrings; i++){
            strings[i] = otherDocument.strings[i];
        }
        return;
    }
    /* 
     * Helper function that deletes all the strings, 
     * and then deletes the
     * array of pointers. Should set strings to NULL when done.
    */
	void Document::deleteStrings(){
//TODO: fix delete to resolve memory leak
        //for(int i=0; i < numStrings; i++);
            //delete strings[i];
            //delete strings;
        return;
    }
