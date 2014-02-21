
/**
 * This program exercises the orderedList class
 * Source File:	main.cpp
 */

#include <iostream>
#include "orderedList.h"
using namespace std;

int main() {
    orderedList<string> stringList;
    orderedList<int> intList;

    intList.insert(8);
    intList.insert(1);
    intList.insert(5);
    intList.insert(2);
    cout << intList.find(4) << endl;
    cout << intList.find(5) << endl;
    cout << intList.toString() << endl;

    stringList.insert("great");
    stringList.insert("Penguin");
    stringList.insert("banana");
    stringList.insert("jungle");
    cout << stringList.find("apple") << endl;
    cout << stringList.find("banana") << endl;
    cout << stringList.toString() << endl;


}

