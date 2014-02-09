package random;
import java.util.Scanner;
import javax.swing.JFileChooser;
import javax. swing.*;
public class throwingExceptions {

	public static double divide(int a, int b){
		double result;
		try{result=a/b;}
		catch(ArithmeticException exception){
			result=0;
		}
		return result;
	}
	
	static Scanner in = new Scanner(System.in);
	public static void main(String[]args){
		int a,b;
		a=b=0;
		double result=0;
		try{
			
			result = a/b;
		}
		catch(ArithmeticException exception){
			result=0;
		}
		
		
		System.out.println("Enter two integers to divide");
		a=in.nextInt();
		b=in.nextInt();
		result = divide(a,b);
		System.out.println(result);
		
		
	}
	
	
	
	
	
}
