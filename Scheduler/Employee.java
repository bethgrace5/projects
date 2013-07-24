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

import javax.swing.ListModel;

//Each Employee will have their own file. 
//

public class Employee /*implements Serializable*/{
	private static String home = System.getProperty("user.home");
	String name;
	String position;
	String altPosition;
	ArrayList <Employee> Employees = new ArrayList<Employee>();
	int[] requestedOff = new int[5];
	//construct Employee with two possible positions
	Employee(String name, String position, String altPosition){
		this.name = name;
		this.position = position;
		this.altPosition = altPosition;
		this.requestedOff = requestedOff;
	}
	//construct Employee with one position
	Employee(String name, String position){
		this.name = name;
		this.position = position;
		this.requestedOff = requestedOff;
	}
	// read a file for an existing employee. load data into buffer?
	public void getEmployee(){
		
		
	}
	//creates a file for a new employee, or overwrite an existing file if Employee name is the same as existing name. 
	public static void editEmployee(Employee person) throws FileNotFoundException{
		File nameFile = new File(home + "\\Documents\\Employees\\"+person.name+".txt");
		PrintWriter out = new PrintWriter(nameFile);
		out.write(person.name);
		out.write(person.position);
		out.write(person.altPosition);
		out.close();
		return;
	}
	public static void removeEmployee(File toRemove){
		//find name of file in path
		//remove file
	}
	
	public static void main(String[] args) throws IOException{
		
		Employee tester = new Employee("name", "positionssss", "altPositionssss");
		
		editEmployee(tester);
		
		
		
		
		
	}

	
}
	
	
	
	
	

