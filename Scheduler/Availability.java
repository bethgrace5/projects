package Scheduler;
import java.util.ArrayList;

/*This class can modify or access a two dimensional array of booleans that correspond
 * to a day(column) and shift(row) that an employee can work. There is 7 days a week, 
 * but the number of available shifts vary by position. 
 */

public class Availability {
final static int DAY = 7;
static boolean[][] weekdays = new boolean[DAY][];
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
