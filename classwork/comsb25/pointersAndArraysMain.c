
/**
* This program 
*
* @author Bethany Armitage
* Course: Comsb25
* Created: Sat 09/28/2013 
* Source File: pointersAndArraysMain.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void concatStrPtr(char *dstr, const char *src);
void concatStrIndex(char dstr[], const char src[]);
int main(){
	char dstr1[80] = { 'A', 'B', 'C', 'D', 'E', '\0' };
	char src1[]    = "1234";
	char dstr2[80] = { 'A', 'B', 'C', 'D', 'E', '\0' };
	char src2[]    = "1234";

	concatStrPtr( dstr1, src1);
	printf("With pointers: %s\n", dstr1);

	concatStrIndex( dstr2, src2);
	printf("With Indices: %s\n", dstr2);

	return 0;
}
