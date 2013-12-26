package Scheduler;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

import javax.swing.JOptionPane;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.control.Button;

public class Event {
	private Employee current;
	
	/**
	 * Creates a Save button and *will* implement events associated with the button.
	 * @return buttonSave button
	 */
	static Button addButtonSave(){
		Button buttonSave = new Button(" Save ");
		buttonSave.setAlignment(Pos.BOTTOM_RIGHT);
		buttonSave.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
		buttonSave.setOnAction(new EventHandler<ActionEvent>(){
			public void handle(ActionEvent event){
				System.out.println("save was pressed.");
				//TODO: create an event that overwrites the selected file with 
				//		current data if any changes are made,
				//		remove file and add new file- in case the name is changed 
				//If "+add new" is selected write a new file for new entry
				//refresh listView: Visual.refreshList();
			}
		});
		return buttonSave;
	}
	/**
	 * Creates a Quit button and *will* implement events associated with the button.
	 * @return buttonQuit button
	 */
	static Button addButtonQuit(){
		Button buttonQuit = new Button("Quit");
		buttonQuit.setAlignment(Pos.BOTTOM_RIGHT);
		buttonQuit.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
		buttonQuit.setOnAction(new EventHandler<ActionEvent>(){
			public void handle(ActionEvent event){
			if(JOptionPane.showConfirmDialog(null, "Are you sure you want to Exit?", 
				"Confirm Delete", JOptionPane.OK_CANCEL_OPTION)==0){
				System.exit(0);
			}
				//TODO: make options only OK_CANCEL
			}
			
		});
		return buttonQuit;
	}
	
	/**
	 * Creates a Delete button and *will* implement events associated with the button.
	 * @return buttonDelete button
	 */
	static Button addButtonDelete(){
		Button buttonDelete = new Button("Delete");
		buttonDelete.setAlignment(Pos.BOTTOM_RIGHT);
		buttonDelete.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
		buttonDelete.setOnAction(new EventHandler<ActionEvent>(){
			public void handle(ActionEvent event){
				//TODO: implement action to remove file of selected employee, and refresh list.
				System.out.println("delete was pressed.");
			}
		});
	return buttonDelete;	
	}
	
	/**
	 * Creates Employees by reading from data from stored files and adds them to currentEmployees
	 * @throws FileNotFoundException
	 */
	public static void populateCurrentEmployees() throws FileNotFoundException{
		for(int i=0; i<Employee.numFiles; i++){
			Scanner in = new Scanner(Visual.listOfFiles[i]); 
			Employee next = new Employee(in.next(), in.next(), in.next());
			Visual.currentEmployees.add(next);
			in.close();
		}
	}
	//TODO: Add listener to listen for selected item in List View empList
	//using the list currentEmployees to reference current Employees,
	//and fill in the text fields with the data of the selected employee.
	
	/*public static ChangeListener<? super String> selectedEmployee() {
		
		
		
		// TODO Auto-generated method stub
		return null;
	}*/
}
	
	
