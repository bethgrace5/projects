package projectEuler;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Properties;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;
/**
 * @author Bethgrace5
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
 */
import java.util.Scanner;
public class Problem3{
	public static ArrayList<Long> append = new ArrayList<Long>();
	public static TreeSet<Long> primesFound = new TreeSet<Long>();
	public static Iterator<Long> checkForFactors1, checkForFactors2; 
	static Long end;
	/**
	 * @param number - the number to generate primes factors of.
	 * @return returnList - the list of number's prime factors.
	 */
	public static ArrayList<Long> primeFactorsof(Long number){
		ArrayList<Long> returnList = new ArrayList<Long>();
		checkForFactors1 = primesFound.iterator();
		end =primesFound.last();
		if (end < number/2){
			for(Long i=end; i<= number/2; i++){
				if (isPrime(i)){
					append.add(i);
				}
			}
		}
		checkForFactors2 = primesFound.iterator(); 
		while (checkForFactors2.hasNext()){
			long next = checkForFactors2.next();
			
			if (next<number/2 && number%next==0){
				returnList.add(next);
				System.out.println(next);
			
		}
		}
		return returnList;
	}
	/**
	 * checks if a number is prime or not.
	 * @param temporary: number to check.
	 * @return primeness: true if prime, false if not.
	 */
	public static boolean isPrime(Long temporary){
		boolean primeness = true;
		if(temporary%2==0){
			return false;
		}
		for (Long i= 3L; i<(temporary/2) ; i+=2){
			if (primeness && temporary%i==0){
				primeness = false;
			}
	}
	return primeness;
	}

	public static void main(String[] args)throws IOException {
		String home = System.getProperty("user.home");
		File dir =  new File(home + "\\Documents\\primesList.txt");
		Scanner numFromFile = new Scanner(dir);
		//loading primesFound with up to date list of primes.
		primesFound.add(1L);
		while(numFromFile.hasNextLong()){
		primesFound.add(numFromFile.nextLong());
		}
		ArrayList<Long> start = new ArrayList<Long>();
		//proof that file is being read and primnesFound is initialized with file contents. 
		System.out.print(primesFound.toString());
		Scanner in = new Scanner(System.in);
		System.out.println("Enter a number to find prime factors of.");
		start = primeFactorsof(in.nextLong());
		PrintWriter out = new PrintWriter(dir);
		System.out.println(start.toString());
		//updating file with newly accumulated data for future use.
		for(int t=0; t<append.size(); t++){
			out.write(append.get(t)+" ");
			System.out.println(append.get(t)+"\n");
		}
		out.close();
		in.close();
		numFromFile.close();
		
	}
}



