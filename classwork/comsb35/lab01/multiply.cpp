
/**
* This program reads two numbers and prints their product
*
* @author Bethany Armitage
* Course: Comsb35
* Created: Tues 01/21/2014
* Source File: multiply.cpp 
*/

#include <iostream>

using namespace std;

int main(){

    double first, second;

  // prompt
    cout << "Enter two numbers: ";

  // read
    cin >> first >> second;

  // print result
    cout << "The product of " << first << " and " << second 
        << " is " << first*second << endl;

    return 0;
}
