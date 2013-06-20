package reddit;


	/* Bethany Armitage
	 * May 29, 2013
	 * Source File: easy127.java
	 * Challenge #127 [easy] McCarthy 91 function display.
	 * prompt: http://redd.it/1f7qp5
	 * output what the McCarthy 91 function does on each recursion.
	 *    M(n) if n>100 subtract 10. if n<=100 add 11. Function Always ends at 91.
	 */

import java.util.Scanner;
public class easy127{
/**
 * prints out steps in McCarthy 91 function.
 * @param n number to begin at.
 * @return
 */
	public static void mcCarthy(int n){
		String put = n +"";
	if((n-10)==91 || (n+11)==91){
		System.out.println(91);
		return;
	}
	else if(n>100){
			put = (n-10) + "";
			System.out.printf("M(%s) since %d is greater than 100\n", put, n);
			n=n-10;
			mcCarthy(n);
		}
	else if (n<=100){
				put = (n+11) + "";
				System.out.printf("M(%s) since %d is less than or equal to 100\n", put, n);
				n= n+11;
				mcCarthy(n);
		}
	}
	public static void main(String args []){
		Scanner in = new Scanner (System.in);
		System.out.println("Enter a starting value for McCarthy 91 function.");
		int n = in.nextInt();
		in.close();
		mcCarthy(n);
	}
	
	
	
	
	
	
	
}
