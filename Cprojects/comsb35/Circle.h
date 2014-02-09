 /**
* Defines Circle class
*
* @author      teacher
* Course:      COMS B35
* Created:     Feb 4, 2013
* Source File: Circle.h
*/

#ifndef H_Circle
#define H_Circle
  
#include "Point.h"

/**
 * This class represents a circle, which is a subclass of Point. It allows
 * getting and setting the radius and center, getting the circumference and area,
 * and determining whether or not this circle overlaps another.
 */
class Circle: public Point
{
public:
   /**
    * Initializes the circle.
    * @param x the x coordinate of the circle.
    * @param y the y coordinate of the circle.
    * @param radius the radius of the circle.
    */
    Circle(double x = 0.0, double y = 0.0, double radius = 0.0);

    /**
     * Prints information about the circle. For the proper format,
     * see the example in the assignment instructions.
     */
    void print() const;

   /**
    * Sets the radius of the circle.
    * @param radius the radius of the circle.
    */
    void setRadius(double radius);

   /**
    * Returns the radius.
    * @return the radius of the circle.
    */
    double getRadius() const;

   /**
    * Returns the circumference of the circle.
    * @return the circumference of the circle.
    */
    double getCircumference() const;

   /**
    * Returns the area of the circle.
    * @return the area of the circle.
    */
    double getArea() const;

   /**
    * Determines whether or not this circle overlaps another.
    * @param other the other circle
    * @return true if this circle overlaps the other circle, and false otherwise.
    */
    bool overlap(const Circle& other) const;

protected:
    double radius;
};

#endif

