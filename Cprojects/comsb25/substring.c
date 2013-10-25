
/**
* This program prints markers underneath any place where a smaller
* string is found in a larger string.
*
* @author Bethany Armitage
* Course: Comsb25
* Created: Wed 10/23/2013 
* Source File: substring.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
	char big[1025];
	char small[65];
	int len =0;
	int i;
	int count = 0;
	char *ptr = '\0';
	char *current = '\0';
	
	printf("Enter string to be searched: ");
	fgets(big, 1025, stdin);

	printf("Enter string to search for: ");
	fgets(small, 65, stdin);

	printf("%s", big);

		//printf("big: %p\nptr: %p\n", big, ptr);
		current = big;
	while( (ptr = strstr(big + len, small)) != NULL
			&& len < strlen(big)-1){
		//printf("big: %p\nptr: %p\n", big, ptr);

		for(  i=0; i<strlen(small) - 1; i++){
			printf(" ");
			len++;
		}
		printf("\b^");

		//printf("len:%d\n count:%d\n", len, count);
		count++;
	}
		current = ptr+strlen(small)-1;
		

return 0;
}
