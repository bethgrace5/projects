
/**
* This file contains strin2int() 
*
* @author Bethany Armitage
* Course: Comsb25
* Created: Fri 10/18/2013 
* Source File: str2int.c
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


/**
* this function changes "string" type integers to "int" type.
* @param char str[] an array of characters (string)
* @return total integer representation of the string.
*/

int string2int(char str[]){
	int current = 0;
	int total = 0; 
	int i=0;
	for(i=0; i<strlen(str); i++){
		if(isdigit(str[i])){
			switch(str[i]){
			case 48: current = 0;
				 break;
			case 49: current = 1;
				 break;
			case 50: current = 2;
				 break;
			case 51: current = 3;
				 break;
			case 52: current = 4;
				 break;
			case 53: current = 5;
				 break;
			case 54: current = 6;
				 break;
			case 55: current = 7;
				 break;
			case 56: current = 8;
				 break;
			case 57: current = 9;
				 break;
			}
		total= (total * 10 ) + current; 
		}
	}
	
return total;

}
