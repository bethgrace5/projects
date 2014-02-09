import java.util.Scanner;


/*accepts a string input and prints it backwards*/

public class pipe{


	public static void main(String[] args){
	Scanner in = new Scanner(System.in);
	String sentence = in.nextLine();

	for(int i=sentence.length(); i>0; --i){

	System.out.print(sentence.substring(i-1,i));
	}
	
	System.out.println();
}
}
