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
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

import javafx.application.Application;

import javax.swing.JOptionPane;
import javax.swing.ListModel;
import javafx.application.Application;

/* This class contains the constructor for creating an Employee.
 * Will be able to edit existing employees, remove employees or add employees.
 */

public class Employee {
	public static String home = System.getProperty("user.home");
	String name;
	String position;
	String altPosition;
	
	// construct Employee with two possible positions
	Employee(String name, String position, String altPosition) {
		this.name = name;
		this.position = position;
		this.altPosition = altPosition;
	}

	// construct Employee with one possible position
	Employee(String name, String position) {
		this.name = name;
		this.position = position;
	}

	/** TODO: read a file for an existing employee.
	 *  This method uses the name of Employee selected in list from Visual.empPane() 
	 *  to access all of their data
	 *  to load into fields in Visual.addFormFields().
	 *  @param: Employee (only the name of Employee is
	 *  @return: Employee
	 */
	public void getEmployee() {
		}

	/**creates a file for a new employee, or overwrite an existing file if
	 * Employee name is the same as existing name.
	 * @param Employee person (an existing Employee)
	 * @return void
	 */
	public static void editEmployee(Employee person)
			throws FileNotFoundException {
		File nameFile = new File(home + "\\Documents\\Employees\\"
				+ person.name + ".txt");
		PrintWriter out = new PrintWriter(nameFile);
		//Later the name, position, and alternate position will be
		//loaded into the form instead of printed out.
		out.println("*name");
		out.println(person.name);
		out.println("*position");
		out.println(person.position);
		out.println("*alternate position");
		out.println(person.altPosition);
		out.close();
		return;
	}
	/** TODO: method will search for file name, and remove file.
	 * @param File toRemove 
	 * @return void
	 * @throws IOException 
	 */
	public static void removeEmployee(Employee person) throws IOException {
		switch(JOptionPane.showConfirmDialog(null, 
				"Are you sure you want to Delete "+person.name+"?", 
				"Confirm Delete", JOptionPane.OK_CANCEL_OPTION)){
		case 0:
			Path del = Paths.get(Visual.folder + person.name + ".txt");
			//FIXME: not deleting...?
			Files.deleteIfExists(del);
			System.out.println(person.name+" Deleted");
			Visual.refreshList();
			break;
		case 1:
			break;
		default:
			break;
		}
	}
	
	public static void main(String[] args) throws IOException {
		Employee tester1 = new Employee("Name1", "Position1",
				"Alternate1");
		Employee tester2 = new Employee("Name2", "Position2",
				"Alternate2");
		editEmployee(tester1);
		editEmployee(tester2);
		Event.loadEmployee(tester1);
		Event.loadEmployee(tester2);
		removeEmployee(tester1);
		Visual.launchGUI();
		
		
		
	}

}
