package projectEuler;



/**
 * @author Bethgrace55
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
 */
import java.util.Scanner;
public class Problem3 {
	/**
	 * generates a list of factors and uses isPrime() to return only the prime factors.
	 * @param number the number to generate factors from.
	 * @return returnList an array of factors that are prime.
	 */
	public static Long[] primeFactorsOf( Long number){
		Long [] returnList = new Long [1000];
		int counter = 0;
		for (Long i=(long) 2; i<(number); i++){
			 Long temp = number%i;
			 if (temp==0){
				 if(isPrime(i)){
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
	public static boolean isPrime(double temporary){
		double [] primesFound = new double [100];
		boolean primeness = true;
		for(double element : primesFound){
			if(temporary==element){
				for(int j=primesFound.length-1; j>0; j--){
				primesFound[j]=primesFound[j-1];	
				}
				primesFound[0]= temporary;
				primeness = true;
				break;
			}
			
		}
		for (int i=2; i<(temporary) && primeness ; i++){
			if (temporary%i==0){
				primeness = false;
		}
	}
	return primeness;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		Long[] start = new Long [100];
		System.out.println("Enter a number to find prime factors of.");
		start = primeFactorsOf(in.nextLong());
		in.close();
		
		for (int i=0; i<100; i++){
			if(start[i+1]==null){
				System.out.println(start[i]);
				break;
			}
		if(isPrime(start[i])){
			System.out.println(start[i]);
		}
		else continue;
		}
	}
}



