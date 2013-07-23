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

	static JList<JCheckBox> monday = new JList<JCheckBox>();
	static 	JList<JCheckBox>  tuesday = new JList<JCheckBox> ();
	static JList<JCheckBox>  wednesday = new JList<JCheckBox>();
	static JList<JCheckBox>  thursday = new JList<JCheckBox> ();
	static JList<JCheckBox>  friday = new JList<JCheckBox> ();
	static JList<JCheckBox>  saturday = new JList<JCheckBox> ();
	static JList<JCheckBox>  sunday = new JList<JCheckBox> ();
	static JList<JCheckBox>  week = new JList<JCheckBox> ();
	static JCheckBox cashier1 = new JCheckBox("7");
	static JCheckBox cashier2 = new JCheckBox("8(T)");
	static JCheckBox cashier3 = new JCheckBox("8");
	static JCheckBox cashier4 = new JCheckBox("9");
	static JCheckBox cashier5 = new JCheckBox("11");
	static JCheckBox cashier6 = new JCheckBox("3");
	static JCheckBox cashier7 = new JCheckBox("3:");
	static JCheckBox super1 = new JCheckBox("7");
	static JCheckBox super2 = new JCheckBox("12");
	static JCheckBox cold1 = new JCheckBox("button");
	static JCheckBox cold2 = new JCheckBox("button");
	static JCheckBox cold3 = new JCheckBox("button");
	//adds each individual checkbox
	public static void addShifts(String position, String altPosition,  JList<JCheckBox> list){
		if(position.equals("cashier")||altPosition.equals("cashier")){
				list.add(cashier1);
				list.add(cashier2);
				list.add(cashier3);
				list.add(cashier4);
				list.add(cashier5);
				list.add(cashier6);
				list.add(cashier7);
				}
			if(Employee.position.equals("super")||Employee.altPosition.equals("super")){
				list.add(super1);
				list.add(super2);
				}
			if(Employee.position.equals("cold")||Employee.altPosition.equals("cold")){
				list.add(super1);
				list.add(super2);
				}				
		}
	
	//change to add 
	public static void buildPositionTable(Employee person){
		JPanel window = new JPanel();
		addShifts(Employee.position, Employee.altPosition, monday);
		addShifts(Employee.position, Employee.altPosition, tuesday);
		addShifts(Employee.position, Employee.altPosition, wednesday);	
		addShifts(Employee.position, Employee.altPosition, thursday);
		addShifts(Employee.position, Employee.altPosition, friday);
		addShifts(Employee.position, Employee.altPosition, saturday);
		addShifts(Employee.position, Employee.altPosition, sunday);
		//add return type of component.
		
		
}
	
	public static void main(String[] args) {
		
		
		
		
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                createAndShowGUI();
            }
        });
        
	}
	
}
