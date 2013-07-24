package Scheduler;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

// A separate space for visual stuff.
// with help from: http://docs.oracle.com/javase/tutorial/uiswing/components/frame.html

public class Visual {
DefaultListModel<String> listModel = new DefaultListModel<String>();
static Employee tester = new Employee("Tester", "cashier");
	
	
	
	
	private static void createAndShowGUI(){
	JFrame frame = new JFrame("Scheduler");
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	
	JLabel someLabel = new JLabel ("");
	someLabel.setPreferredSize(new Dimension(650, 450));
	
	frame.getContentPane().add(someLabel, BorderLayout.CENTER);

	frame.pack();
	frame.setVisible(true);	
	frame.setLocationRelativeTo(null);
	JTextArea names = new JTextArea(100, 100);

		
	}	

	
	public static void main(String[] args) {
		
		
		
		
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                createAndShowGUI();
            }
        });
        
	}
	
}
