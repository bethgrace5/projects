package projectEuler;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
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
	public static TreeSet<Long> primesFound = new TreeSet<Long>();
	public static Iterator<Long> checkForFactors = primesFound.iterator();
	/**
	 * @param number - the number to generate primes factors of.
	 * @return returnList - the list of number's prime factors.
	 */
	public static ArrayList<Long> primeFactorsof(Long number){
		ArrayList<Long> returnList = new ArrayList<Long>();
		if (primesFound.last() < number/2){
			for(Long i=primesFound.last()+1; i<= number/2; i++){
				if (isPrime(i)){
					primesFound.add(i);
				}
			}
		}
		//FIXME: Iterator not iterating, or else returnList would be adding factors from primesFound. 
		while (checkForFactors.hasNext()){
			long next = checkForFactors.next();
			if (number%next==0){
				returnList.add(next);
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
		while(numFromFile.hasNextLong()){
		primesFound.add(numFromFile.nextLong());
		}
		
		ArrayList<Long> start = new ArrayList<Long>();
		//proof that file is being read. 
		System.out.print(primesFound.toString());
		Scanner in = new Scanner(System.in);
		System.out.println("Enter a number to find prime factors of.");
		
		start = primeFactorsof(in.nextLong());
		FileWriter fw = new FileWriter(dir, true);
		PrintWriter out = new PrintWriter(fw);
		
		out.close();
		in.close();
		numFromFile.close();
			System.out.println(start.toString());
	}
}



