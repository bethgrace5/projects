package Scheduler;

import java.awt.event.ItemEvent;
import java.io.File;
import java.util.ArrayList;

import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Control;
import javafx.scene.Scene;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.control.Button;
import javafx.scene.control.CheckBox;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.Tab;
import javafx.scene.control.TabPane;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import javafx.scene.input.InputEvent;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;

/* This class will set the GUI for manipulating Employee class.
 * Events connecting GUI to Employee class may be put into a different class.
 * 
 * Currently: Setting Skeletons for windows and Options. 
 *            Setting Panels with various I/O techniques.
 *            
 * Next:      Look at working with Event Handling.
 *       
 * Eventually: fine-tune looks with CSS, and methods of java/javaFX.
 */

public class Visual extends Application{
	static File folder = new File(Employee.home + File.separator + 
				"Documents" + File.separator + "Employees" + File.separator);
	static File[] listOfFiles = folder.listFiles();
	static ListView<String> empList = new ListView<String>();
	static ArrayList<Employee> currentEmployees = new ArrayList<Employee>(Employee.numFiles);
	String selectedItem = null;
	int selectedIndex = 1;
	private static TextField name;
	private static TextField phone;
	private static ComboBox<String> positions;
	private static ComboBox<String> altPositions;
	
	
	
	static Label[] weekdays ={new Label("Monday"), new Label("Tuesday"), new Label("Wednesday"),
			new Label("Thursday"), new Label("Friday"), new Label("Saturday"), new Label("Sunday")};
	static Label[] shifts = {new Label("s1"), new Label("c1"), new Label("c2"), new Label("c3"), 
		new Label("c4"), new Label("p1"), new Label("p2")};
	
	//TODO: change CheckBoxes to clickable color boxes
	//		green=available, yellow=not preferable, red=unavailable 
	static CheckBox [] s1 = {new CheckBox(), new CheckBox(), new CheckBox(),
		new CheckBox(), new CheckBox(), new CheckBox()};
	
	static CheckBox [] c1 ={new CheckBox(), new CheckBox(), new CheckBox(), 
		new CheckBox(), new CheckBox(), new CheckBox()};
	
	static CheckBox [] c2 = {new CheckBox(), new CheckBox(), new CheckBox(), 
		new CheckBox(), new CheckBox(), new CheckBox()};
	
	static CheckBox [] c3 ={new CheckBox(), new CheckBox(), new CheckBox(), 
		new CheckBox(), new CheckBox(), new CheckBox()};
	
	static CheckBox [] c4 = {new CheckBox(), new CheckBox(), new CheckBox(), 
		new CheckBox(), new CheckBox(), new CheckBox()};
	
	static CheckBox [] p1 ={new CheckBox(), new CheckBox(), new CheckBox(), 
		new CheckBox(), new CheckBox(), new CheckBox()};
	
	static CheckBox [] p2 ={new CheckBox(), new CheckBox(), new CheckBox(), 
		new CheckBox(), new CheckBox(), new CheckBox()};
	
	
	public static void launchGUI(){
		Application.launch();
	}
	/**
	 * JavaFX uses main() in Employee to launch start(). this method uses several other methods 
	 * to build GUI. 
	 * @param: Stage primaryStage -the Stage is the Window.
	 */
	@Override
	public void start(Stage primaryStage) {
		TabPane tabs = new TabPane();
		
		Tab employee = new Tab();
		employee.setText("Employee");
		employee.setStyle("-fx-font-size: 18pt");
		employee.setClosable(false);
		employee.setContent(empPane());
		
		Tab schedule = new Tab();
		schedule.setText("Schedule");
		schedule.setStyle("-fx-font-size: 18pt");
		schedule.setClosable(false);
		schedule.setContent(schPane());
		//schedule.setContent(schPane());
		
		tabs.getTabs().addAll(employee, schedule);
		
		Scene scene = new Scene(tabs, 900, 400);
		primaryStage.setMinWidth(900);
		primaryStage.setMinHeight(400);
		primaryStage.setMaxWidth(900);
		primaryStage.setMaxHeight(400);
		primaryStage.setTitle("Employee Staff Management");
		//Change title when tabs change (After Implementing Events and Actions.
		//primaryStage.setTitle("Employee Staff Management");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	/**
	 * Creates Content for Employee tab
	 * @return:emp BorderPane
	 */
	private Pane empPane(){
		//List of existing employees
		BorderPane emp = new BorderPane();
        emp.setPadding(new Insets(10, 10, 10, 10));

		refreshList();
		
		empList.getSelectionModel().select(0);
		empList.setMaxHeight(300);
	    empList.setPrefWidth(150.0);
	    empList.requestFocus();
	    empList.addEventHandler(MouseEvent.MOUSE_CLICKED, 
	   	new EventHandler<MouseEvent>(){
	    	public void handle(MouseEvent e){
	    		//the if statement is to avoid an infinite loop for now
	    		//though there's probably a better way- need to look at event.consume().
    			if(empList.getSelectionModel().getSelectedIndex() == selectedIndex){
	    		}
    			else{
	   				selectedItem = empList.getSelectionModel().getSelectedItem();
	   				selectedIndex = empList.getSelectionModel().getSelectedIndex();
	   				System.out.println(selectedItem);
	   				
	   				//if "+add new" option is selected fill in appropriate prompt text.
	   				  if (selectedItem.equals("+add new")){
	   					name.clear();
	   					phone.clear();
	   					name.setPromptText("Enter new name");
	   					phone.setPromptText("Enter contact number");
   						positions.getSelectionModel().select(0);
   						altPositions.getSelectionModel().select(0);
	   					}
	   				
	   				//search through the list of current Employees for selected Item in list.
	   				for(int j=0; j<currentEmployees.size(); j++){
		
	   					if(currentEmployees.get(j).name.equals(selectedItem)){
	   						System.out.println("match");
	   						name.setText(currentEmployees.get(j).name);
	   						phone.setText(currentEmployees.get(j).contact);
	   						positions.getSelectionModel().select(currentEmployees.get(j).position);
	   						altPositions.getSelectionModel().select(currentEmployees.get(j).altPosition);
	   					}
	   					
	   				}
    			}
	   				
	    }
	   	});
	    
	    emp.setLeft(empList);
		emp.setCenter(addFormFields());
		emp.setBottom(createButtonRow());
		emp.setRight(createCheckboxes());
		
		return emp;
	}
	/**
	 * Unfinished content for Schedule Tab
	 * @return:sch 
	 */
	private Pane schPane(){
		BorderPane sch = new BorderPane();
		sch.setPadding(new Insets(10, 10, 10, 10));
		sch.setLeft(text());
		sch.setCenter(schedule());
		//sch.setTop();
		return sch;
	}
	/**
	 * Creates bottom row button options for Employee Pane
	 * @return: foot HBOx, the footer of buttons
	 */
	private static HBox createButtonRow(){
		HBox foot = new HBox();
		foot.setPadding(new Insets(0, 20, 30, 650));
		foot.setSpacing(10);	
		foot.getChildren().addAll(Event.addButtonDelete(), Event.addButtonSave(), Event.addButtonQuit());
		return foot;
	}
	/**
	 * Adds the form fields and drop lists to the center of Employee Tab. Currently displays entries blank.
	 * TODO: show Stats about Selected employee, or blank if adding new employee
	 * TODO: (when implementing Events)Call Employee.editEmployee() for editing or adding.
	 * @return: GridPane grid 
	 */
	private static GridPane addFormFields(){
		GridPane grid = new GridPane();
		grid.setHgap(10);
		grid.setVgap(10);
		grid.setPadding(new Insets(0, 10, 10, 40));
		grid.setMinSize(300, 100);
		grid.setAlignment(Pos.TOP_LEFT);
		Label empName = new Label("Employee Name:");
		Label position = new Label("Position:");
		Label altPosition = new Label("Alternate Position:");
		Label cell = new Label("Contact");
		name = new TextField();
		phone = new TextField();
		
		ObservableList<String> poslist = FXCollections.observableArrayList("", "position1", "Position2", "position3");  
		positions = new ComboBox<String>(poslist);
		
		positions.getSelectionModel().select(0);
		positions.setPrefWidth(150);
		
		altPositions = new ComboBox<String>(poslist);
		altPositions.setPrefWidth(150);
		altPositions.setMinWidth(150);
		altPositions.getSelectionModel().select(0);
		grid.add(empName, 0,0);
		grid.add(name, 1,0);
		grid.add(position, 0, 1);
		grid.add(positions, 1,1);
		grid.add(altPosition, 0, 2);
		grid.add(altPositions, 1, 2);
		grid.add(cell, 0,3);
		grid.add(phone,  1, 3);
		
		//grid.setGridLinesVisible(true);
		return grid;
	}
	/**
	 *adds all the checkBox arrays in a GridPane
	 * @return boxes GridPane
	 */
	private static GridPane createCheckboxes(){
		GridPane boxes = new GridPane();
		//boxes.setGridLinesVisible(true);
		boxes.setHgap(10);
		boxes.setVgap(10);
		boxes.setPadding(new Insets(0, 20, 0, 40));
		
	
		for(int i =1; i<7; ++i){
			boxes.add(weekdays[i-1], i, 0);
			boxes.add(shifts[i-1], 0, i);
			if(i==6){
			boxes.add(shifts[6], 0, 7);
			}
			if(s1[i-1] != null){
			boxes.add(s1 [i-1], i, 1);
			boxes.add(c1 [i-1], i, 2);
			boxes.add(c2 [i-1], i, 3);
			boxes.add(c3 [i-1], i, 4);
			boxes.add(c4 [i-1], i, 5);
			boxes.add(p1 [i-1], i, 6);
			boxes.add(p2 [i-1], i, 7);
			}
		}
		//boxes.setGridLinesVisible(true);
		return boxes;
	}
	/**
	 * Creates Text area to unfinished Schedule Tab
	 * @return text textArea
	 */
	private static TextArea text(){
		TextArea text = new TextArea();
		//text.setEditable(true);
		text.setPrefHeight(100);
		text.setPromptText("Notes, Reminders, Comments, Events . . . ");
		return text;
	}
	/**
	 * Skeleton for a visual schedule
	 * @return grid gridPane
	 */
	private static GridPane schedule(){
		GridPane grid = new GridPane();
		return grid;
	}
	/**
	 * refreshes the observable list- useful after new employee is added or one is updated.
	 */
	public static void refreshList(){
		//TODO: re-count numFiles as it should have changed if a file was added/deleted
		ObservableList<String> listCurrentEmployees = FXCollections.observableArrayList();
		listCurrentEmployees.add("+add new");
		for(int i=0; i<Employee.numFiles; i++){
			listCurrentEmployees.add(currentEmployees.get(i).name);
		}
		empList.setItems(listCurrentEmployees);
		return;
	}
}
