
#include <string>

using namespace std;

/**
 * This class models a student.
 *
 * @author        Bethany Armitage
 * Course:        COMS B25
 * Created:       Mon 12/02/2013 
 * Source File:   Student.h 
 */

class Student {

public:
   /*
    * Constructs a Student object with name studentName
    * @param studentName the student name
    */
   Student( string name )
    { setStudentName( name ); }

   /*
    * Sets Student name to studentName
    * @param studentName the student name
    */
   void setStudentName( string name )
        { studentName =  name; }

   /*
    * Returns Student name
    * @return studentName
    */
   string getStudentName( void ) const
        { return studentName; }


private:
    string studentName;

};
