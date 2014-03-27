

#include <iostream>
#include <string>
#include "Stack.h"
#include "unorderedLinkedList.h"

using namespace std;

/**
* Analyzes input string for grouping-symbol (parenthesis, square
* brackets, and curly braces) mismatches and returns the index of
* the first mismatch, or -1 if no mismatch is found. If not all
* open symbols have matches, reutrn length of input string.
*
* @param str string to analyze
* @return either index of first mismatch, length of string if
* closing grouping symbol is missing, or -1 if mo mismatch found.
*/
int matchGroupingSymbols ( string str ){
    unorderedLinkedList<char> *list = new unorderedLinkedList<char>();
    int length = str.length();

    for(int i=0; i< length; i++){
        if (str.at(i) == ("{" || "(" || "[")){
            cout << "found begin " << endl;
            //list.push(str.at(i));
            //return i;
        }
        else if (str.at(i) ==  ("}" || ")" || "]")){
            cout << "found end" << endl;
            //return i;
        }
    }

    return -1;

}

int main() {
    string input;
    cout << "Enter strings to be analyzed.";
    cout << " Enter empty string when done.\n";
    do {
        getline(cin, input);
        int mismatchLocation;
        if (input.length() > 1){
            if ((mismatchLocation = matchGroupingSymbols(input))
                    == - 1) {
                cout << "Symbols Match " << endl;
            }
            else {
                cout << "Symbols do not match: \n" << input << endl;
                for (int i = 0; i < mismatchLocation; ++i)
                    cout << " ";
                    cout << "^" << endl;
            }
        }
    }
    while ((input.length() > 1));
    return 0;
}

