package Scheduler;
import java.util.ArrayList;

/*This class can modify or access a two dimensional array of booleans that correspond
 * to a day(column) and shift(row) that an employee can work. There is 7 days a week, 
 * but the number of available shifts vary by position. 
 */

public class Availability {
final static int DAY = 7;
static boolean[][] weekdays = new boolean[DAY][];

//each list is a shift that will be populated with people who can work that shift
//there are 10 spots to add available people, and 7 days for the week.
String[][] super1 = new String[10][7];
String[][] cash1 = new String[10][7];
String[][] cash2 = new String[10][7];
String[][] cash3 = new String[10][7];
String[][] cash4 = new String[10][7];
String[][] cash5 = new String[10][7];
String[][] cold1 = new String[10][7];
String[][] cold2 = new String[10][7];
String[][] super2 = new String[10][7];
String[][] cold3 = new String[10][7];
String[][] cash6 = new String[10][7];
String[][] cash7 = new String[10][7];

//



//construct Availability specific to each person
	public Availability(Employee person){
		
	}
	
	public static boolean[][] get_available_days(){
		return weekdays;
	}
	
	//call Availability.set_available_day() for each check-box that is checked.
	public static boolean set_available_day(int day, int shift){
		weekdays[day][shift] = true;
		
	}
	
	
	
	
}
