/*
* A program that exercises the Circle class.
*
* @author      teacher
* Course:      COMS B35
* Created:     Feb 4, 2013
* Source File: testCircle.cpp
*/

#include <iostream>
#include <iomanip>
#include "Circle.h"

using namespace std;

int main() {
   Circle circle1(2, 2, 3);
   Circle circle2(0, 6, 2);
   Circle circle3;
   double x = 4, y = 6;
   double r = 1.4722;

   cout << fixed << showpoint;
   cout << setprecision(2);

   cout << "***** Circle 1 *****" << endl;
   circle1.print();
   cout << endl;

   cout << "***** Circle 2 *****" << endl;
   circle2.print();
   cout << endl;

   circle3.setPoint(x, y);
   circle3.setRadius(r);

   cout << "***** Circle 3 *****" << endl;
   circle3.print();
   cout << endl;

   cout << "Circle 1 does " << (circle1.overlap(circle2) ? "" : "NOT ")
         << "overlap Circle 2\n";
   cout << "Circle 1 does " << (circle1.overlap(circle3) ? "" : "NOT ")
         << "overlap Circle 3\n";
   cout << "Circle 2 does " << (circle2.overlap(circle3) ? "" : "NOT ")
         << "overlap Circle 3\n";

   return 0;
}

