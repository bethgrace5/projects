/**
 * This program exercises the Document class
 *
 * @author 		professor
 * Course: 		COMS B35
 * Created: 	Feb 15, 2013
 * Source File:	main.cpp
 */

#include <iostream>
#include "Document.h"
using namespace std;

int main() {
	cout << "Making doc1\n";
	Document doc1;
	doc1.addString("One");
	doc1.addString("Two");
	doc1.addString("Three");
	doc1.printDocument();
	cout << endl;

	{
		cout << "\nMaking doc2\n";
		Document doc2;
		doc2 = doc1;
		doc2.printDocument();
	} // doc2 goes out of scope (destructor called)

	cout << "\nMaking doc3\n";
	Document doc3(doc1);
	doc3.printDocument();
	cout << endl;

	doc3.getStringAt(doc3.getNumStrings());
}

