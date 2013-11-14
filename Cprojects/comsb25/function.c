
/**
* This file contains function bitN(); 
*
* @author Bethany Armitage
* Course: Comsb25
* Created: Sun 11/10/2013 
* Source File: function.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 
 * This function returns bit N in a decimal number.
 * @param N index of bit (index 0 begins at least significant bit)
 * @param number the decimal number in which to find bit N
 * @return 1 if there is a bit in position N, 0 if not.
 */
int bitN(int number, int N){
    if((1<<N) & number)
        return 1;
    else
        return 0;
}

