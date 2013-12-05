#include <iostream>
#include <string>
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
}

void GradeBook::setInstructorName( string name ){
    instructorName = name;
}

string GradeBook::getCourseName(){
    return courseName;
}

string GradeBook::getInstructorName(){
    return instructorName;
}

void GradeBook::addStudent( string name ){
    Student person = Student( name );
    students.insert(students.end(),person);
}

void GradeBook::printGradeBook( void ){
    
    cout << "Course: " << GradeBook::getCourseName() << endl;
    cout << "Instructor: " << GradeBook::getInstructorName() << endl;
    cout << endl;
    cout << "Students" << endl;
    
    for(unsigned int i=0; i< GradeBook::students.size(); i++){
        cout << " "<< (i+1) << ". " << students[i].getStudentName();
        cout << endl;
        
    }
}
