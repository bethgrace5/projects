
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;

public class searchFile{
public static void main(String [] args) throws FileNotFoundException
{
File letter = new File("C:/Users/Bethgrace55/Documents/letter.txt");
File number = new File("C:/Users/Bethgrace55/Documents/number.txt");
Scanner in1 = new Scanner (letter);
Scanner in2 = new Scanner (number);

for (int i=0; i<5; i++){
String let = in1.next();
String num = in2.next();

System.out.println(let + num);
}
in1.close();
in2.close();


	}
}
