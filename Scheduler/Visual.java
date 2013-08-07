package Scheduler;

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Control;
import javafx.scene.Scene;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.control.Button;
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
		
		Scene scene = new Scene(tabs, 650, 450);
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
        emp.setPadding(new Insets(20, 10, 20, 10));
		ListView<String> empList = new ListView<String>();
		ObservableList<String> list = FXCollections.observableArrayList("+add new", "name1", "name2", "name3", "name4", "name5", "name6");
		
		empList.setItems(list);
		empList.setMaxHeight(100);
	    empList.setPrefWidth(150.0);
	    
	    
		emp.setLeft(empList);
		emp.setCenter(addFormFields());
		emp.setBottom(createButtonRow());
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
		
		Button buttonSave = new Button(" Save ");
		buttonSave.setAlignment(Pos.BOTTOM_RIGHT);
		buttonSave.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
		
		Button buttonCancel = new Button("Cancel");
		buttonCancel.setAlignment(Pos.BOTTOM_RIGHT);
		buttonCancel.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
		foot.getChildren().addAll(buttonDelete, buttonSave, buttonCancel);
		
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
		grid.setPadding(new Insets(10, 10, 10, 10));
		
		Label empName = new Label("Employee Name:");
		Label position = new Label("Position:");
		Label altPosition = new Label("Alternate Position:");
		Label cell = new Label("Cell Phone");
		TextField name = new TextField();
		TextField cellp = new TextField();
		
		ObservableList<String> poslist = FXCollections.observableArrayList("position1", "Position2", "position3");  
		ComboBox positions = new ComboBox(poslist);
		
		ComboBox altPositions = new ComboBox(poslist);
		
		grid.add(empName, 0,0);
		grid.add(name, 1,0);
		grid.add(position, 0, 1);
		grid.add(positions, 1,1);
		grid.add(altPosition, 0, 2);
		grid.add(altPositions, 1, 2);
		
		return grid;
	}
}
