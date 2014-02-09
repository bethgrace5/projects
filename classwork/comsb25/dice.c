

/**
*
* This program simulates rolling a 4-sided dice.
* @author Bethany Armitage
* Course: comsB25
* Created :Mon 09/16/2013 
* Source File: dice.c 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tetrahedralDieToss(int numRolls);

int main(){
	int number = 0;
	
	//seeding time
	srand( time(NULL));

	printf("Enter number of times to toss 4-sided dice: ");
	scanf("%d", &number);
	tetrahedralDieToss(number);
return 0;

}

/**
* This function simulates rolling a 4-sided dice.
* @param numRolls the number of times to roll the dice.
* @return void
*/
void tetrahedralDieToss(int numRolls){
	int tosses[4] = {0, 0, 0, 0};
	for(int i=0; i< numRolls; ++i){
		switch(  rand()% 4 + 1){
			case 1:
				tosses[0]++;
				break;
			case 2:
				tosses[1]++;
				break;
			case 3:
				tosses[2]++;
				break;
			case 4:
				tosses[3]++;
				break;
		}
	}
	printf("1 is rolled %d times\n", tosses[0]);
	printf("2 is rolled %d times\n", tosses[1]);
	printf("3 is rolled %d times\n", tosses[2]);
	printf("4 is rolled %d times\n", tosses[3]);

}

