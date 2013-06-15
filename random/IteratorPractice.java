package random;
import java.util.TreeSet;
import java.util.Iterator;


public class IteratorPractice {
	public static void main(String[] args){
		TreeSet<String> words = new TreeSet<String>();	
		Iterator<String> printWords = words.iterator();
		words.add("the");
		words.add("and");
		words.add("cat");
		
	while (printWords.hasNext()){
		System.out.println(printWords.next());
	}
	}
	
}	
