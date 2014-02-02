/*
* A program that exercises the Lexicon class.
*
* @author      Hal Mendoza
* Course:      COMS B35
* Created:     Jan 25, 2013
* Source File: Lexicon._test.cpp
*/

#include "Lexicon.h"
#include <iostream>
using namespace std;

int main() {
	Lexicon lexicon("nhanced North American Benchmark Lexicon.txt");
	string word;

	cout << "Enter words to be checked. Enter EOF (Ctrl-z on Windows) when you are done\n";
	cin >> word;
	while (!cin.eof()) {
		cout << word << " is" << (lexicon.isWord(word) ? "":" NOT") << " a word\n";
		cin >> word;
	}
}
