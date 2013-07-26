package Scheduler;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Control;
import javafx.scene.control.ListView;
import javafx.scene.control.Tab;
import javafx.scene.control.TabPane;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
// A separate space for visual stuff.
// with help from: http://docs.oracle.com/javase/tutorial/uiswing/components/frame.html
// Using JavaFX help from: http://docs.oracle.com/javafx/2/layout/jfxpub-layout.htm"
import javafx.stage.Stage;

public class Visual extends Application{


	public static void main(String[] args) {
		Application.launch(args);
		}
	
	@Override
	public void start(Stage primaryStage) {
		TabPane tabs = new TabPane();
		
		Tab employee = new Tab();
		employee.setText("Employee");
		employee.setContent(empPane());
		
		Tab schedule = new Tab();
		schedule.setText("Schedule");
		//schedule.setContent(schPane());
		
		tabs.getTabs().addAll(employee, schedule);
		
		Scene scene = new Scene(tabs, 650, 450);
		primaryStage.setTitle("Employee Staff Management");
		//Change title when tabs change (After Implementing Events and Actions.
		//primaryStage.setTitle("Employee Staff Management");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	private Pane empPane(){
		BorderPane emp = new BorderPane();
        //emp.setPadding(new Insets(10,10, 10, 10));
		ListView<String> empList = new ListView<String>();
		ObservableList<String> list = FXCollections.observableArrayList("name1", "name2", "name3", "name4");
		
		empList.setItems(list);
		
		empList.setMaxHeight(Control.USE_PREF_SIZE);
	    empList.setPrefWidth(150.0);
		emp.setLeft(empList);
		//emp.setRight();
		//emp.setBottom(createButtonRow());
		return emp;
	}
	private static HBox createButtonRow(){

		HBox foot = new HBox();
		//foot.setPadding(new Insets(10, 20, 10, 20));
		foot.setSpacing(10);
		Button buttonDelete = new Button("Delete");
		Button buttonSave = new Button("Save");
		Button buttonCancel = new Button("Cancel");
		//foot.getChildren().addAll(buttonDelete, buttonSave);
		
		
	}
}
