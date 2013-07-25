package Scheduler;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

import javafx.scene.Scene;
import javafx.scene.control.Tab;
import javafx.scene.control.TabPane;
// A separate space for visual stuff.
// with help from: http://docs.oracle.com/javase/tutorial/uiswing/components/frame.html
// Using JavaFX help from: http://docs.oracle.com/javafx/2/layout/jfxpub-layout.htm"
import javafx.stage.Stage;

public class Visual {


	public static void main(String[] args) {
		//javax.swing.SwingUtilities.invokeLater(new Runnable() {
			//public void run() {
				//createAndShowGUI();
			}
	
	public void start(Stage primaryStage) {
		TabPane tabs = new TabPane();
		Tab employee = new Tab();
		employee.setText("Employee");
		//employee.setContent(method returning Node value);
		
		Tab schedule = new Tab();
		schedule.setText("Schedule");
		//schedule.setContent(method returning Node value);
		
		tabs.getTabs().addAll(employee, schedule);
		
		Scene scene = new Scene(tabs, 650, 450);
		primaryStage.setTitle("Employee Staff Management");
		//Change title when tabs change (After Implementing Events and Actions.
		//primaryStage.setTitle("Employee Staff Management");
		primaryStage.setScene(scene);
		primaryStage.show();
	}

	
}
