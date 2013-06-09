package projectEuler;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Properties;
import java.util.Set;
/**
 * @author Bethgrace5
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
 */
import java.util.Scanner;
public class Problem3{
	public static Set<Long> primesFound = new HashSet<Long>(100);
	public static Iterator<Long> checkForFactors = primesFound.iterator();
	/**
	 * @param number - the number to generate primes factors of.
	 * @return returnList - the list of number's prime factors.
	 */
	public static ArrayList<Long> primeFactorsof(Long number){
		ArrayList<Long> returnList = new ArrayList<Long>();
		if (Collections.max(primesFound) < number/2){
			for(Long i=Collections.max(primesFound)+1; i<= number/2; i++){
				if (isPrime(i)){
					primesFound.add(i);
	/*
	 *TODO: use a print writer to add new primes to primesArchive File.
	 */
				}
			}
		}
		while (checkForFactors.hasNext()){
			if (number%checkForFactors.next()==0){
				returnList.add(checkForFactors.next());
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
	
	public static void main(String[] args)throws FileNotFoundException {
		String home = System.getProperty("user.home");
		Scanner numFromFile = new Scanner("C:/Users/" + home + "/Documents/primesList.txt");
		//loading primesFound with up to date list of primes.
		while(numFromFile.hasNextLong()){
			primesFound.add(numFromFile.nextLong());
		}
		
		ArrayList<Long> start = new ArrayList<Long>();
		
		Scanner in = new Scanner(System.in);
		System.out.println("Enter a number to find prime factors of.");
		
		start = primeFactorsof(in.nextLong());
		in.close();
		numFromFile.close();
			System.out.println(start.toString());
	}
}



