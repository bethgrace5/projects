package Scheduler;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

//this class constructs Employees and has main in it.
//I want to create a panel that has input areas to create or modify Employees.
//Create a File to store Employee data
//Create a File to store generated Schedules

public class Employee{
	static String name, primary_position, alt_position;
	public ArrayList <Employee> Employees = new ArrayList<Employee>();
	
	Employee(String name, String primary_position, String alt_position, int num_workdays){
		this.name = name;
		//or name = this.name;?
		this.primary_position = primary_position;
		this.alt_position = alt_position;
		
		
	}
	
	public static void main(String[] args) throws FileNotFoundException{
		/*show starting screen- Two options available
		 * ---------------------------------------------------------------------------------------
		 * 1.)EMPLOYEE button-leads to new screen with:
		 * 	a.)NEW: Construct and save a new employee.
		 * 	b.)EDIT: access and modify existing employee.(select from drop-down list)
		 * 	c.)DELETE: remove employee: (select from drop-down list)
		 * ----------------------------------------------------------------------------------------
		 * 2.)SCHEDULE button-leads to new screen with:
		 * 	a.)MODIFY Employee availability: (select from drop-down list)leads to check-boxes to set availability.
		 * 		- each employee's availability check-box page will display days requested off, and have
		 * 			an option for requesting a day off. displays a column of weekdays by a row of possible shifts.
		 * 		-figure out a way to set advanced availability individually (for when college semester/quarter starts).
		 * 	b.)VIEW SCHEDULE- asks for week, displays schedule if generated, if not, displays
		 * 					blank skeleton schedule in "schedule view".
		 * 		-GENERATE or (REFRESH if already generated) schedule (add warning if refreshing -data will be lost).
		 * 			(randomly generates schedule based on current Employee settings.)
		 * 		----------schedule will need to be modified for various reasons----------
		 * 		-Manually SWAP two selected people (people like to switch shifts often)
		 * 		-Manually REPLACE a selected person to another person (people take over shifts,
		 * 						and for various other reasons).
		 * 		-add a NOTE for a specific shift (come in early, organize storage, tomatoes, 11-close etc.)
		 * 		-PRINT current schedule.
		 * 		-SAVE schedule.
		 * 		-General NOTES to display(like a little plain text editor with some text editing options)
		 * 			-to display events, reminders, comments, etc.(with a SAVE and EDIT option in itself).
		 * 		-display people who requested days off and when.
		 *  
		 *  
		 */
		Scanner readEmployees = new Scanner(new File ("employee_data.txt"));
		Scanner readSchedule = new Scanner(new File ("schedule_data.txt"));
		
		readEmployees.close();
		readSchedule.close();
		
	}

	
}
	
	
	
	
	

