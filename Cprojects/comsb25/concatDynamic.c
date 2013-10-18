
/**
* File contains concatStrDynamic(). 
*
* @author Bethany Armitage
* Course: Comsb25
* Created: Thu 10/17/2013 
* Source File: concatDynamic.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
* This function concatenates two strings by using a pointer
* and allocating enough memory for the result.
* @param string1 the first string (gets added first)
* @param string2 the second string (gets added second)
* @return ptr the pointer to the resulting concatenation
*/
char *concatStrDynamic(char *string1, char *string2){
	int count1 = 0;
	int count2 = 0;
	int i = 0;
	//count the length of string1
	for(i=0;*(string1+i) != '\0'; i++)
		count1++;
	//count the length of string2
	for(i=0;*(string2+i) != '\0'; i++)
		count2++;

	//allocate enough space for both strings and an ending NULL
	char *ptr = malloc(count1 + count2 +1);

	for(i=0; i<count1; i++)
		*(ptr + i)=*(string1 + i);
	for(i=0; i<count2; i++)
		*(ptr + count1 + i)=*(string2 + i);
	//set final character of concatenation to NULL
	*(ptr + count1 + count2) = '\0';

return ptr;
}
