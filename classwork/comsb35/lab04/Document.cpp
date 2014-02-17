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
        for(int i=0; i < numStrings; i++)
            delete strings[i];
        delete strings;
    }
	const Document& Document::operator=(const Document& otherDocument){
        copyDoc(otherDocument);
        return *this;
    }
	bool Document::addString(string str){
        if( numStrings < maxStrings ){
            strings[numStrings] = new string[30];
            *strings[numStrings++] = str;
            cout << numStrings<<endl;
            return true;
        }
        return false;
    }
    // this function needs to be const
	string Document::getStringAt(int index) const {
        cout << numStrings << " " << index << endl;
        if( index > numStrings)
            cerr << "Invalid index!" << endl;
        cout<< *strings[index] << endl;
        return *strings[index];
    }
	void Document::printDocument(){
        cout << strings << endl;
        for (int i=0; i < numStrings; i++){
            cout << *strings[i] << " (" << strings[i] << "(" << endl;
        }
    }
	void Document::copyDoc(const Document& otherDocument){
        cout << " numStrings" << numStrings << endl;
        for(int i=0; i < numStrings; i++){
            //this->addString(otherDocument.getStringAt(i));
            *strings[i] = otherDocument.getStringAt(i);
            //cout << i << ":"<< *strings[i] << " " << otherDocument.getStringAt(i);
        }
        cout << "return from copy" << endl;
        return;
    }
    /* 
     * Helper function that deletes all the strings, 
     * and then deletes the
     * array of pointers. Should set strings to NULL when done.
    */
	void deleteStrings(){
        return;
    }
