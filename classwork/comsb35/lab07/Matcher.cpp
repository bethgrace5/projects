/**
 *  parses a string for matching grouping symbols. Notifies user if 
 *  symbols match or not. If symbols do not match, shows location of error
 *  @author         Bethany Armitage
 *  course:         COMS B35
 *  created:        Thu 03/20/2014 
 *  source file:    Matcher.cpp  
 */

#include <iostream>
#include <string>
#include "Stack.h"

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
    Stack<char> list;
    int length = str.length();
    char c;

    for(int i=0; i<length; i++){
        c = str.at(i);
        // check for opening symbol
        if( c== '(' || c== '[' || c =='{'){
            list.push(c);
        }

        // check for closing symbol
        else if( c== ')' || c== ']' || c =='}'){
            // compare c with top of stack.
            if(!list.isEmptyStack()){
                if     (c == ')' && list.top() == '('){
                    list.pop();
                }
                else if(c == '}' && list.top() == '{'){
                    list.pop();
                }
                else if(c == ']' && list.top() == '['){
                    list.pop();
                }
                else { 
                    return i; //c did not match top of stack
                }
            }
            else{
                return i; //grouping symbol was found, but stack was empty
            }
        }
        // opening symbol has not been matched with closing by end
        if ( i== length-1 && !list.isEmptyStack()) {
            return length;
        }
    }
    // if this point is reached, string does not have mismatched symbols
    return -1;
}

// Main supplied by instructor
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
