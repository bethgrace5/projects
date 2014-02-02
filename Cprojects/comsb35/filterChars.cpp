/**
* This program reads line by line to filter out any characters
* that are not a space, an uppercase letter or a lowercase letter
*
* @author Bethany Armitage
* Course: Comsb35
* Created: 01/22/2014 
* Source File: filterChars.cpp
*/

#include <iostream>
#include <string>
#include <cstdio>
#include <cctype>

using namespace std;

void removeNonAlpha( string& str);
bool isUpperCaseLetter( char ch);
bool isLowerCaseLetter( char ch);

int main(){

    string tempStr;
    
    //read strings until End of file is reached
    while( getline(cin, tempStr)){
        removeNonAlpha( tempStr );
    }
    return 0;
}

/**
* this function uses isUpperCaseLetter() and isLowerCaseLetter()
* to print characters that are upper case or lower case letters
* in addition it checks if a character is a space and prints it
* @param str the input string to filter
*/
void removeNonAlpha( string& str){
    int length = str.length();
    char c;
    int i;
    //check each character to see if it is a letter
    for ( i=0; i< length; i++){
        c = str.at(i);
        if( (isUpperCaseLetter(c) || isLowerCaseLetter(c)) )
            putchar(c); 

    //32 is the ASCII value for a space
        if( (int) c == 32 )
            putchar( c );
    }
    cout << endl;
}

/**
* this function tests if a character is an uppercase letter by directly
* comparing it's ascii value to those of uppercase letters
* @param ch the character to test
* @return false by default, true if charater is uppercase
*/
bool isUpperCaseLetter( char ch){
    int asciiNum = (int) ch;

    // 64-91 are the ASCII equivalents of uppercase letters
    if (asciiNum > 64 && asciiNum < 91)
        return true;
    return false;
}

/**
* this function tests if a character is an lowercase letter by directly
* comparing it's ascii value to those of lowercase letters
* @param ch the character to test
* @return false by default, true if charater is lowercase
*/
bool isLowerCaseLetter( char ch){
    int asciiNum = (int) ch;

    // 64-91 are the ASCII equivalents of lowercase letters
    if (asciiNum > 96 && asciiNum < 123)
        return true;
    return false;
}


