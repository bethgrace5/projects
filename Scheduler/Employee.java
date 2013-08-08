package Scheduler;

import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Serializable;
import javafx.application.Application;
import javax.swing.ListModel;
import javafx.application.Application;

/* This class contains the constructor for creating an Employee.
 * Will be able to edit existing employees, remove employees or add employees.
 * 
 * 
 * 
 */

public class Employee /* implements Serializable */{
	// private static final long serialVersionUID = 655451095884888984L;
	private static String home = System.getProperty("user.home");
	String name;
	String position;
	String altPosition;
	ArrayList<Employee> Employees = new ArrayList<Employee>();
	int[] requestedOff = new int[5];

	// construct Employee with two possible positions
	Employee(String name, String position, String altPosition) {
		this.name = name;
		this.position = position;
		this.altPosition = altPosition;
		this.requestedOff = requestedOff;
	}

	// construct Employee with one position
	Employee(String name, String position) {
		this.name = name;
		this.position = position;
		this.requestedOff = requestedOff;
	}

	/** TODO: read a file for an existing employee. load data into buffer?
	 *  This method uses the name of Employee selected in list from Visual.empPane() to access all of their data
	 *  to load into fields in Visual.addFormFields().
	 *  @param: Employee (only the name of Employee is
	 *  @return: Employee
	 */
	public void getEmployee() {

	}

	/**creates a file for a new employee, or overwrite an existing file if
	 * Employee name is the same as existing name.
	 * @param Employee person -an existing Employee
	 * @return void
	 */
	public static void editEmployee(Employee person)
			throws FileNotFoundException {
		File nameFile = new File(home + "\\Documents\\Employees\\"
				+ person.name + ".txt");
		PrintWriter out = new PrintWriter(nameFile);
		out.println(person.name);
		out.println(person.position);
		out.println(person.altPosition);
		out.close();
		return;
	}
	/** TODO: method will search for file name, and remove file.
	 * @param File toRemove 
	 * @return void
	 */
	public static void removeEmployee(File toRemove) {
		//TODO how to remove a file
	}

	
	public static void main(String[] args) throws IOException {
		Employee tester = new Employee("name", "position",
				"altPosition");
		editEmployee(tester);
		Visual.launchGUI();
		//TODO: Launch Visual from main in Employee.
		
	}

}
