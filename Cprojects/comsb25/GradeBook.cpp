#include <iostream>
#include "GradeBook.h"

using namespace std;

/**
 * This file contains the function implementations for classe GradeBook
 *
 * @author        Bethany Armitage 
 * Course:        COMS B25
 * Created:       Mon 12/02/2013 
 * Source File:   GradeBook.cpp
 */

GradeBook::GradeBook( string name ){
   setCourseName( name );
}

void GradeBook::setCourseName( string name ){
      courseName = name;
      // Instructed to remove character limit
}

void GradeBook::setInstructorName( string name){
    instructorName = name;
}

string GradeBook::getCourseName(){
   return courseName;
}

string GradeBook::getInstructorName(){
    return instructorName;
}

void GradeBook::addStudent( string name ){
    Student person = Student(name);
    GradeBook::students[GradeBook::count] = person;
    GradeBook::count++;
}

void printGradeBook(){
    
    cout << "Course:" << GradeBook::getCourseName(students[0]) << endl;
    cout << "Instructor:" << GradeBook::getInstructorName(students[0]) 
        << endl;
    cout << "Students" << endl;
    
    for(int i=0; i< GradeBook::students.size(); i++){
        cout << GradeBook::students[i] << endl;
    }
}
