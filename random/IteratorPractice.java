package random;
import java.util.TreeSet;
import java.util.Iterator;


public class IteratorPractice {
	public static void main(String[] args){
		TreeSet<Integer> numbers = new TreeSet<Integer>();	
		Iterator<Integer> printNumbers = numbers.iterator();
		numbers.add(3);
		numbers.add(2);
		numbers.add(4);
		numbers.add(3);
	
		System.out.println(numbers.toString());
	
	}
	
}	
