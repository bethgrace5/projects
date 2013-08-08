package Scheduler;

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
import javafx.scene.control.TextField;
import javafx.stage.Stage;
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
	static Label[] weekdays ={new Label("Monday"), new Label("Tuesday"), new Label("Wednesday"),
			new Label("Thursday"), new Label("Friday"), new Label("Saturday"), new Label("Sunday")};
	static Label[] shifts = {new Label("s1"), new Label("c1"), new Label("c2"), new Label("c3"), 
		new Label("c4"), new Label("p1"), new Label("p2")};
	
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
	 * JavaFX uses main() to launch start(). this method uses several other methods to build GUI.
	 * From the top down:
	 * -Stage is set (JavaFX for Window)
	 * -within stage is a Scene
	 * -the Scene contains a tabPane
	 * -Each tab in the TabPane has its own Border Pane
	 * -the BorderPanes are sectioned off into various other panes
	 *   (Hbox, Vbox, GridPane, )
	 * - Each pane has its own contents (Labels, FormFields, Buttons etc). 
	 * @param: Stage primaryStage -the Stage is the Window.
	 * @return: void
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
		//schedule.setContent(schPane());
		
		tabs.getTabs().addAll(employee, schedule);
		
		Scene scene = new Scene(tabs, 900, 350);
		primaryStage.setTitle("Employee Staff Management");
		//Change title when tabs change (After Implementing Events and Actions.
		//primaryStage.setTitle("Employee Staff Management");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	/**
	 * Creates Content for Employee tab
	 * @return: emp BorderPane
	 */
	private Pane empPane(){
		//List of existing employees
		BorderPane emp = new BorderPane();
        emp.setPadding(new Insets(10, 10, 10, 10));
		ListView<String> empList = new ListView<String>();
		ObservableList<String> list = FXCollections.observableArrayList("+add new", "name1", "name2", "name3", "name4", "name5", "name6");
		
		empList.setItems(list);
		empList.getSelectionModel().select(0);
		empList.setMaxHeight(300);
	    empList.setPrefWidth(150.0);
	    //TODO: set default focus to selected item in empList upon launch.
	    //empList.requestFocus();
	    
		emp.setLeft(empList);
		emp.setCenter(addFormFields());
		emp.setBottom(createButtonRow());
		emp.setRight(createCheckboxes());
		return emp;
	}
	/**
	 * Creates bottom row button options for Employee Pane
	 * @return: foot HBOx, the footer of buttons
	 */
	private static HBox createButtonRow(){

		HBox foot = new HBox();
		foot.setPadding(new Insets(10, 20, 10, 20));
		foot.setSpacing(10);
		Button buttonDelete = new Button("Delete");
		buttonDelete.setAlignment(Pos.BOTTOM_RIGHT);
		buttonDelete.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
		buttonDelete.setOnAction(new EventHandler<ActionEvent>(){
			public void handle(ActionEvent event){
				System.out.println("delete was pressed.");
			}
			
		});
		
		
		Button buttonSave = new Button(" Save ");
		buttonSave.setAlignment(Pos.BOTTOM_RIGHT);
		buttonSave.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
		buttonSave.setOnAction(new EventHandler<ActionEvent>(){
			public void handle(ActionEvent event){
				System.out.println("save was pressed.");
			}
			
		});
		
		Button buttonQuit = new Button("Quit");
		buttonQuit.setAlignment(Pos.BOTTOM_RIGHT);
		buttonQuit.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
		buttonQuit.setOnAction(new EventHandler<ActionEvent>(){
			public void handle(ActionEvent event){
				System.out.println("quit was pressed.");
			}
			
		});
		foot.getChildren().addAll(buttonDelete, buttonSave, buttonQuit);
		//TODO move buttons to the far right
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
		grid.setMinSize(100, 100);
		grid.setAlignment(Pos.TOP_LEFT);
		Label empName = new Label("Employee Name:");
		Label position = new Label("Position:");
		Label altPosition = new Label("Alternate Position:");
		Label cell = new Label("Contact");
		TextField name = new TextField();
		name.setPromptText("New Employee Name");
		TextField cellp = new TextField();
		
		ObservableList<String> poslist = FXCollections.observableArrayList("position1", "Position2", "position3");  
		ComboBox<String> positions = new ComboBox<String>(poslist);
		
		positions.getSelectionModel().select(0);
		positions.setPrefWidth(150);
		
		ComboBox<String> altPositions = new ComboBox<String>(poslist);
		altPositions.setPrefWidth(150);
		altPositions.getSelectionModel().select(0);
		grid.add(empName, 0,0);
		grid.add(name, 1,0);
		grid.add(position, 0, 1);
		grid.add(positions, 1,1);
		grid.add(altPosition, 0, 2);
		grid.add(altPositions, 1, 2);
		grid.add(cell, 0,3);
		grid.add(cellp,  1, 3);
		
		//grid.setGridLinesVisible(true);
		return grid;
	}
	private static GridPane createCheckboxes(){
		GridPane boxes = new GridPane();
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
}
