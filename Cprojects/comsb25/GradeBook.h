#include <string>
using namespace std;

/**
 * This class models a gradebook.
 *
 * @author        Instructor
 * Course:        COMS B25
 * Created:       November 26, 2013
 * Source File:   GradeBook.h
 */

class GradeBook {
public:
   /*
    * Constructs a GradeBook object with course name courseName
    * @param courseName the course name
    */
   GradeBook (string);

   /*
    * Sets course name to courseName
    * @param courseName the course name
    */
   void setCourseName(string courseName);

   /*
    * Returns course name
    * @return course name
    */
   string getCourseName();
  
   /*
    * Sets instructor name to instructorName
    * @param instructorName the instructor name
    */
   void setInstructorName( string instructorName );

   /*
    * Returns instructor name
    * @return instructor name
    */
   string getInstructorName();

   /*
    * adds a student to "TODO student vector"
    * @param StudentName the student name
    */
   void addStudent( string Studentname );

   /*
    * prints current version of gradebook 
    */
   void printGradeBook( void );

private:
   string courseName;
   string instructorName;
   // TODO: add a vector of class Student
};
