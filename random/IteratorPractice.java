package random;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.TreeSet;
import java.util.Iterator;
import java.util.Scanner;
import java.io.PrintWriter;
public class IteratorPractice {
	public static void main(String[] args) throws FileNotFoundException{
		TreeSet<Integer> numbers = new TreeSet<Integer>();	
		Iterator<Integer> printNumbers = numbers.iterator();
		File printNumbersTo= new File(System.getProperty("user.home")+"\\Documents\\someNumbers.txt");
		Scanner read = new Scanner (new File( System.getProperty("user.home")+"\\Documents\\number.txt"));
		PrintWriter pw = new PrintWriter(printNumbersTo);
		while( read.hasNextInt()){
			numbers.add(read.nextInt());
			}
		pw.print(numbers.toString());
		pw.close();
		read.close();
	}
	
}	
