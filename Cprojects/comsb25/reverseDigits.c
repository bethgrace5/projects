/*
 * this program: accepts an integer and prints it backwards.
 * @author Bethany Armitage
 * Course: Comsb25
 * Created: 9/15/2013
 * Source File: reverseDigits.c
*/

#include <stdio.h>

void printReverseInteger(int number);

int main(){
	int input;
	printf("Enter integer to print backwards: ");
	scanf("%d", &input);
	printReverseInteger(input);
	return 0;
}

/** This function prints an integer backwards.
 *@param number (an integer to print backwards.)
 *@return void
 */
void printReverseInteger(int number){
	if(number<=0)
		return;
	printf("%d", number%10);
	printReverseInteger(number / 10);
	}

