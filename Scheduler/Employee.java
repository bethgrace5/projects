package Scheduler;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.Serializable;

import javax.swing.ListModel;

//Each Employee will have their own file. 
//

public class Employee implements Serializable{
	static String name, position, altPosition;
	static ArrayList <Employee> Employees = new ArrayList<Employee>();
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
	//use ObjectInputStream to read a file for an existing employee. load data into buffer?
	public void getEmployee(/*path*/){
		
		
	}
	//use ObjectOutputStream to create a file for a new employee, or overwrite an existing file for changes.
	public File setEmployee(){
		//calls constructor to create Employee, (whether existing or not)
		//if exists, overwrite file and return location
		//if not exists, return new file location
	}
			
	
	
	public static void main(String[] args) throws FileNotFoundException{
	
		
	}

	
}
	
	
	
	
	

