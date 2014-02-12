
/**
* Implements Circle class
*
* @author  Bethany Armitage 
* Course:      COMS B35
* Created:     Feb 8, 2013
* Source File: Circle.cpp
*/

#include "Circle.h"
#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES

    // Circle inherits from Point
    Circle::Circle(double x, double y, double radius) : Point(x, y) {
        setRadius(radius);
    }

    void Circle::print() const {
        std::cout << "Center: ";
        Point::print();

        std::cout <<"Radius: "
            << Circle::getRadius() << std::endl;

        std::cout <<"Circumference: " 
            << Circle::getCircumference() << std::endl;

        std::cout <<"Area: "
            << Circle::getArea()   << std::endl;
    }

    void Circle::setRadius(double radius){
        Circle::radius = radius;
        return;
    }

    double Circle::getRadius() const {
        return Circle::radius;
    }

    double Circle::getCircumference() const {
        return (2 * M_PI * getRadius());
    }

    double Circle::getArea() const {
        return (M_PI * getRadius() * getRadius());
    }

    bool Circle::overlap(const Circle& other) const {
        // calculate distance between center points
        // (x1 - x2)^2 + (y1 - y2)^2 
        int pointDistance = pow((Point::getX() - other.getX()), 2.0) +
            pow((Point::getY() - other.getY()), 2.0);

        // calculate distance of both radii
        // (r1 + r2)^2
        int radiusDistance= pow( getRadius() + other.getRadius(), 2.0);

        if (pointDistance <= radiusDistance )
            return true;  // overlaps
        else
            return false; // does not overlap
    }

