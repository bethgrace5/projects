#include <iostream>
#include "GradeBook.h"
using namespace std;

/**
 * This program exercises the GradeBook class
 *
 * @author        Instructor
 * Course:        COMS B25
 * Created:       November 26, 2013
 * Source File:   GradeBookTester.cpp
 */

int main() {
   GradeBook gradeBook("COMS B25 Programming with C ");
   gradeBook.setInstructorName("Tennessee Tuxedo");

   gradeBook.addStudent("Adam Ant");
   gradeBook.addStudent("Brigitte Bardot");
   gradeBook.addStudent("Courteney Cox");
   gradeBook.addStudent("Danny DeVito");
   gradeBook.addStudent("Emilio Estevez");
   gradeBook.addStudent("Frederic Forrest");
   gradeBook.addStudent("Godric Gryffindor");
   gradeBook.addStudent("Huckleberry Hound");
   gradeBook.addStudent("Ivan Ilych");
   gradeBook.addStudent("J. Jonah Jameson");

   gradeBook.printGradeBook();

}
