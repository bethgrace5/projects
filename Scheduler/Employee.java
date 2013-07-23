package Scheduler;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

import javax.swing.ListModel;

//this class constructs Employees and has main in it.
//I want to create a panel that has input areas to create or modify Employees.
//Create a File to store Employee data
//Create a File to store generated Schedules
//will probably change several arrays/ArrayLists to other kinds of sets/tables.

public class Employee{
	static String name, position, altPosition;
	static ArrayList <Employee> Employees = new ArrayList<Employee>();
	Employee(String name, String position, String altPosition){
		this.name = name;
		this.position = position;
		this.altPosition = altPosition;
	}
	Employee(String name, String position){
		this.name = name;
		this.position = position;
	}
	public static String names(){
		
		return "name 1";
	}
	//this function looks at each specific day, to see if person can work that day.
	public boolean isAvailable(Employee person, int day){
		boolean canwork=true;
		
		if(person.requestedOff.contains(date)){
			canwork=false;
		}
		for(i=0,j=0,k=0; somecondition && canwork; ++i, ++j, ++k){
			
			if(person.shifts.contains()){
				ListAvailablePeople[i][j][k]
				
				
			}
			
			
			
		}
		
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
		Employees.add(new Employee("a", "cashier"));
		Employees.add(new Employee("b", "cold"));
		Employees.add(new Employee("c", "super", "cashier"));
		Employees.add(new Employee("d", "super", "cold"))
;		
		Scanner readEmployees = new Scanner(new File ("employeeData.txt"));
		Scanner readSchedule = new Scanner(new File ("scheduleData.txt"));
		
		readEmployees.close();
		readSchedule.close();
		
	}

	
}
	
	
	
	
	

