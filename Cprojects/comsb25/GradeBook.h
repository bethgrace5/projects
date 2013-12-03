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
private:
   string courseName;
};
