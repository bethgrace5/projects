package Scheduler;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Event {

	public static void loadEmployee(Employee person) throws FileNotFoundException{
		Scanner in = new Scanner(Visual.folder+ person.name + ".txt");
		String temp;
		while(in.hasNextLine()){
			temp= in.nextLine();
			if(!temp.startsWith("*")){
	//TODO: eventually this will load the data to the form instead of printing to console.
				System.out.println(temp+ " ");
				}
		}
		in.close();
		System.out.println("successfully loaded " + person.name +"'s data");
	}
	
	
	
}
