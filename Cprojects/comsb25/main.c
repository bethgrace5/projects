
/**
* This program uses bitN() contained in function.c to convert 
* a decimal number to its binary equivalent.
*
* @author Bethany Armitage
* Course: Comsb25
* Created: Tue 11/12/2013 
* Source File: main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int bitN (int number, int N);
unsigned int numBits = sizeof(unsigned int)*CHAR_BIT;

int main(int argc, char *argv[]){
    int i;

    for(i=numBits-1; i>=0; i--){
        printf("%d", bitN(atoi(argv[1]), i));
    }
    
    return 0;
}
