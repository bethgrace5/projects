/**
 * Document is a class that holds a list of strings
 *
 * @author 		Hal Mendoza
 * Course: 		COMS B35
 * Created: 	Feb 15, 2013
 * Source File:	Document.h
 */

#ifndef DOCUMENT_H_
#define DOCUMENT_H_

#include <string>

class Document {
public:
    /*
    * Make room for initialSize strings
    * @param initialSize the maximum number of string that this document can hold
    */
	Document(int initialSize = 100);

	
    /*
     * Copy Constructor
     * @param otherDocument the document of which to make a copy
    */
	Document(const Document& otherDocument);

	virtual ~Document();

    /*
     * Overload the assignment operator
     * @param otherDocument the document of which to make a copy
    */
	const Document& operator=(const Document& otherDocument);

    /*
	 * If there is room in array, add dynamically-allocated string to
	 * end of list of strings and return true , else return false
     * @param str the string to add to this Document
     * @return true if there is room to add str, false otherwise
    */
	bool addString(std::string str);

    /* 
     * Return string at index if index is a valid index, else emit
     * an error msg by writing to cerr and exit
     * @param index the index of the string to return
     * @return string at index
    */
	std::string getStringAt(int index) const;

    /* 
     * Print this Document
    */
	void printDocument();


    /* 
     * Return number of strings in this Document
     * @return number of strings in this Document
    */
    int getNumStrings() const
    {
        return numStrings;
    }

private:
    // pointer to dynamically-allocated array of pointers to strings
	std::string **strings;
	int numStrings; // number of strings in list of strings
	int maxStrings; // maximum number of strings that document can hold

    /* 
     * Helper function that copies otherDocument to this Document
     * @param otherDocument the document of which to make a copy
    */
	void copyDoc(const Document& otherDocument);

    /* 
     * Helper function that deletes all the strings, and then deletes the
     * array of pointers. Should set strings to NULL when done.
    */
	void deleteStrings();
};

#endif /* DOCUMENT_H_ */

