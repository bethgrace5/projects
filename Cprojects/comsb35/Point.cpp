 //Implementation File pointTypeImp.cpp
 
#include <iostream>
#include "Point.h"
  
using namespace std;

void Point::setPoint(double x, double y) {
    xCoordinate = x;
    yCoordinate = y;
}

void Point::print() const {
    cout << "(" << xCoordinate << ", " << yCoordinate << ")" << endl;
}

double Point::getX() const {
    return xCoordinate;
}

double Point::getY() const {
    return yCoordinate;
}

Point::Point(double x, double y) {
    xCoordinate = x;
    yCoordinate = y;
}


