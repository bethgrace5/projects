package random;
import java.util.TreeSet;
import java.util.Iterator;
public class IteratorPractice {
	public static void main(String[] args){
		TreeSet<Integer> numbers = new TreeSet<Integer>();	
		numbers.add(2);
		numbers.add(9);
		numbers.add(7);
		numbers.add(3);
		numbers.add(2);
		Iterator<Integer> printNumbers = numbers.iterator();
		while (printNumbers.hasNext()){
			System.out.print(printNumbers.next()+", ");
		}
	}
	
}	
