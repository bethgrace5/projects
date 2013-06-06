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
/*
 * FIXME: my methods don't like to access a private set, nor will main() reference private variables
 * therefore, I have it set as static.
 */
		static Set<Long> primesFound = new HashSet<Long>(500);{
			Long num = in1.nextLong();
/*FIXME: (line 23-25) initializing HashSet primesFound with list of primes in the File is not working.	
 * I want to move the declaration of PrimesFound to main() so it's guaranteed to run, but
 * then I'm worried about methods belonging to the class being able to access the HashSet.  
 */
			for (int a=0; a<100; a++){
				primesFound.add(num);
			}
			in1.close();
		}
	/**
	 * generates a list of factors and uses isPrime() to return only the prime factors.
	 * @param number the number to generate factors from.
	 * @return returnList an array of factors that are prime.
	 */
	public static Long[] primeFactorsOf( Long number){
		Long [] returnList = new Long [1000];
		int counter = 0;
		for (Long i= 2L; i<(number); i++){
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
		if(primesFound.contains(temporary)){
				return true;
			}
		for (Long i= 2L; i<(temporary) && primeness ; i++){
			if (temporary%i==0){
				primeness = false;
			}
			if (i==(temporary-1)&& primeness ){
				primesFound.add(temporary);
				primeness=true;
			}
	}
	return primeness;
	}
	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		Long[] start = new Long [100];
		System.out.println("Enter a number to find prime factors of.");
		start = primeFactorsOf(in.nextLong());
		in.close();
		System.out.print(primesFound.toString());
		for (int i=0; i<100; i++){
			if(start[i+1]==null){
				System.out.println(start[i]);
				break;
			}
		if(isPrime(start[i]))
			System.out.println(start[i]);
		else continue;
		}
	}
}



