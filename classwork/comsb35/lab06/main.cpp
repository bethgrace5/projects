/*
 * This program tests the SortedLinkedList class.
 *
 * @author      Hal Mendoza
 * Course:      COMS B35
 * Created:     March 7, 2014
 * Source File: main.cpp
 */
#include <iostream>
#include <string>
#include "SortedLinkedList.h"

using namespace std;

void doSomeWork() {
	SortedLinkedList<string> list;

	list.add("D");
	list.add("C");
	list.add("E");
	list.add("B");
	list.add("A");
	list.add("B");

	string s = "F";
	cout << s << " does" << (list.exists(s) ? "" : " not") << " exist in list\n";
	s = "C";
	cout << s << " does" << (list.exists(s) ? "" : " not") << " exist in list\n";

	cout << list << endl;

    s = "A";
	list.remove(s);
	cout << "After removing " << s << endl;
	cout << list << "|" << endl;

    s = "C";
	list.remove(s);
	cout << "After removing " << s << endl;
	cout << list << "|" << endl;

    s = "E";
	list.remove(s);
	cout << "After removing " << s << endl;
	cout << list << "|" << endl;

    s = "E";
	list.remove(s);
	cout << "After removing " << s << endl;
	cout << list << "|" << endl;

	cout << "Output from mystery()" << endl;
	list.mystery();
}

int main() {
	cout << "Calling doSomeWork()\n";
	doSomeWork();
	cout << ("doSomeWork() returns\n");
}
