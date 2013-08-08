package Scheduler;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Event {

	public static void loadEmployee(String employee) throws FileNotFoundException{
		File empFile = new File (Employee.home + "\\Documents\\Employees\\"+ employee + ".txt");
		Scanner in = new Scanner(empFile);
		while(in.hasNext()){
		System.out.println(in.next()+ " ");
		}
		in.close();
		System.out.println("successfully loaded " + employee +"'s data");
	}
	
	
	
}
