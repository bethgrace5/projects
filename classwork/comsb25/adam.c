
/**
* This program adds command line arguments given that there are
* at least two.
*
* @author Bethany Armitage
* Course: Comsb25
* Created: Fri 10/25/2013 
* Source File: adam.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[] ){
	double total = 0;
	int i=0;
 
	if(argc < 3){
		puts("Not enough arguments supplied");
		exit(2);
	}

	for(i=0; argv[i] != NULL; i++){
		total += strtod(argv[i], NULL);
	}
	printf("%f", total);


return 0;
}
