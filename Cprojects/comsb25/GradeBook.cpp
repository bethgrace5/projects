#include <iostream>
#include "GradeBook.h"
using namespace std;

/**
 * This file contains the function implementations for class GradeBook.
 *
 * @author        Instructor 
 * Course:        COMS B25
 * Created:       November 26, 2013
 * Source File:   GradeBook.cpp
 */

GradeBook::GradeBook( string name )
{
   setCourseName( name );
}

void GradeBook::setCourseName( string name ) {
   if ( name.length() <= 25 )
      courseName = name;

   if ( name.length() > 25 ) { 
      courseName = name.substr( 0, 25 );

      cout << "Name \"" << name << "\" exceeds maximum length (25).\n"
         << "Limiting courseName to first 25 characters.\n" << endl;
   } // end if
}

string GradeBook::getCourseName()
{
   return courseName;
}
