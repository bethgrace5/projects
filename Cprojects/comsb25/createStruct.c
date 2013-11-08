
/**
* This program prints a typdedef of a struct named Transaction,
* reads a file formatted "string, string, double"
* and prints  the file contents as an array of Transactions to standard out
*
* @author Bethany Armitage
* Course: Comsb25
* Created: Sun 11/03/2013 
* Source File: createStruct.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    int counter = 0;
    char *sender   = malloc(sizeof(char) * 32);
    char *reciever = malloc(sizeof(char) * 32);
    double amount;

    //print typedef Transaction
    printf( "typedef struct {\n"
            "\tchar *sender, *receiver;\n"
            "\tdouble amount;"
            "} Transaction;\n");
    
    //begin print for array of Transaction
    printf( "Transaction transactions[] = {\n");
   
    //print input for array initialization
    while(scanf("%s%s%lf",sender, reciever, &amount)!= EOF){
        printf("\t{\"%s\", \t\"%s\",   \t %4.2f},\n", 
            sender, reciever, amount);
        counter++;
    }

    //print end of Transaction
    puts("};");

    //initialize count
    printf("int count = %d;",counter);

        
        



	return 0;
}
