#include <iostream>
#include "GradeBook.h"
#include "Student.h"
using namespace std;

/**
 * This file contains the function implementations for classes GradeBook
 * and Student.
 *
 * @author        Bethany Armitage 
 * Course:        COMS B25
 * Created:       Mon 12/02/2013 
 * Source File:   GradeBook.cpp
 */

GradeBook::GradeBook( string name ){
   setCourseName( name );
}

Student::Student( string name ){
    setStudentName( name );
}

void GradeBook::setCourseName( string name ){
      courseName = name;
      // Instructed to remove character limit
}

void Student::setStudentName( string name ){
      studentName = name;
      // Instructed to remove character limit
}

void GradeBook::setInstructorName( string name){
    instructorName = name;
}

string GradeBook::getCourseName(){
   return courseName;
}

string Student::getStudentName(){
   return studentName;
}

string GradeBook::getInstructorName(){
    return instructorName;
}

void GradeBook::addstudent( string name ){
    setStudentName( name );
    // TODO add studentName to vector of class student
    // vectorspot = Student.studentName 
    // advance vector spot?
}

void printGradeBook(){
    cout << Course: << getCourseName() endl;
    cout << Instructor: << getInstructorName() endl;
    cout << Students endl;
    
    for(int i=0; i< /*TODO sizeof vector*/; i++){
        cout << /*TODO get vectorspot[i]*/ endl;
    }
}
