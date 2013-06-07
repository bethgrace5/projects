package projectEuler;



import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Set;
/**
 * @author Bethgrace55
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
 */
import java.util.Scanner;
public class Problem3{
		private Scanner in1 = new Scanner("C:/Users/Bethgrace55/Documents/primesList.txt");
		private static Set<Long> primesFound = new HashSet<Long>(500);
	/**
	 * generates a list of factors and uses isPrime() to return only the prime factors.
	 * @param number the number to generate factors from.
	 * @return returnList an array of factors that are prime.
	 */
	public static Long[] primeFactorsOf( Long number){
		Long [] returnList = new Long [100];
		int counter = 0;
		for (Long i= 3L; i<=(number/2); i+=2){
			 Long temp = number%i;
			 if (temp==0){
				 if( primesFound.contains(i) || isPrime(i)){
					 returnList[counter]=i;
					 counter++;
				 }
			}
		}
	
	return returnList;
	}
	/**
	 * checks if a number is prime or not.
	 * @param temporary number to check.
	 * @return primeness (true or false)
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
			if (primeness){
				primesFound.add(i);
			}
	}
	return primeness;
	}
	
	public static void main(String[] args)throws FileNotFoundException {
		File primesList = new File ("C:/Users/Bethgrace55/Documents/primesList.txt");
		Scanner fileReader = new Scanner(primesList);
		for (int i=0; i<5098; i++){
			primesFound.add(fileReader.nextLong());
		}
		Long[] start = new Long [100];
		Scanner in = new Scanner(System.in);
		System.out.println("Enter a number to find prime factors of.");
		start = primeFactorsOf(in.nextLong());
		in.close();
		
		
		for (int i=0; i<100; i++){
			System.out.println(start[i]);
			if(start[i+1]==null){
				break;
			}
		}
		
	}
}



