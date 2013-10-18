
/**
* This program 
*
* @author Bethany Armitage
* Course: Comsb25
* Created: Thu 10/17/2013 
* Source File: testDynamic.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *concatStrDynamic(char *string1, char *string2);

int main(){
	char s1[]="ABCDEFGHI";
	char s2[]="1234";
	char *s12;

	s12= concatStrDynamic(s1, s2);
	printf("s1=%s\ns2=%s\ns12=%s\n", s1, s2, s12);
	free(s12);

return 0;
}
