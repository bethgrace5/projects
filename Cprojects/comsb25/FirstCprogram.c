/**
 * program accepts two numbers that specify a range, 
 * then analyzes a list of numbers, printing only those that are inside of the specified range.
 * @author ****************
 * Course: COMS B25
 * Created : Aug 27, 2012
 * Source File: FirstCprogram.c
 */


#include <stdio.h>

int main(void){
	int first, second, next, counter, i;
	int numbers[100];
	
	//first is the lowerbound, second is the upperbound.
	scanf("%d%d",&first, &second);
	
	while(scanf("%d", &next) != EOF){
		if(next >= first && next <= second){
			numbers[counter] = next;
			counter++;
		} 
	}
	printf("numbers included between %d and %d include:\n", first, second);
	for(i=0; i<counter; ++i){
		printf("%d\n", numbers[i]);
	}
	
	
	return 0;
}