package random;

import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;

public class fileReader{
public static void main(String [] args) throws FileNotFoundException
{
File primesList = new File("C:/Users/Bethgrace55/Documents/primesList.txt");
Scanner in1 = new Scanner (primesList);
for (int i=0; i<100; i++){
Long let = in1.nextLong();
System.out.println(let);
}
in1.close();



	}
}