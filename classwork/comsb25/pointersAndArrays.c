
/**
* This program 
*
* @author Bethany Armitage
* Course: Comsb25
* Created: Sat 09/28/2013 
* Source File: pointersAndArrays.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
* This function concatenates a source string to a destination string
* by using array indicies.
* @param dstr[] an array of characters (destination string)
* @param src[] an array of characters (source string)
* @return void
*/
void concatStrIndex(char dstr[], const char src[]){
	int i, j;
	for(i=0; i<100; i++){
		if(dstr[i] == '\0'){
			for(j=0; j<100; j++){
				dstr[i] = src[j];
				i++;
			}
			dstr[j] = '\0';
		}
	}
	return;
}

/**
* This function concatenates a source string to a destination string
* by using pointers.
* @param dstr[] an array of characters (destination string)
* @param src[] an array of characters (source string)
* @return void
*/

void concatStrPtr(char *dstr, const char *src){
	int i = 0;
	while(*dstr != '\0'){
		dstr++;
	}
	
	while(*src != '\0'){
		*dstr = *src;			
		dstr++;
		src++;
	}	

	
	
return;
}
