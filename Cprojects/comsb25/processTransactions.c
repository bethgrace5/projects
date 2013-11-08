
/**
* This program includes the structure definition created by createStruct.c,
* and searches the structure for particular items.
*
* @author Bethany Armitage
* Course: Comsb25
* Created: Sun 11/03/2013 
* Source File: processTransactions.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "transactions.h"

int main(){

    char *name = malloc(sizeof(int)*32);
    char *tmpname = malloc(sizeof(int)*32);
    int isSender = 1;
    int isReceiver = 1;
    int i = 0;
    double total = 0;
    Transaction data;
    int numberTransactions = sizeof(transactions)/sizeof(transactions[i]);

    printf("Number of Transactions = %d\n", count);
    printf("Enter name: ");
    scanf("%s", tmpname);
    name = tmpname;

    //format name to all lowercase with the first character uppercase
    while(tmpname[i]){
        name[i] = tolower(tmpname[i]);
        i++;
    }
    name[0] = toupper(tmpname[0]);

    //search list of transactions created by createStruct.c for the name
    //and record net change for the name
    for(i=0; i<numberTransactions; i++){
        data = transactions[i];
        isSender = strcmp(data.sender, name);     //set to zero if equal
        isReceiver = strcmp(data.receiver, name); //set to zero if equal
        
        if(isSender == 0){
            total -= data.amount;
            isSender = 1; //reset isSender 
        }
        else if(isReceiver == 0){
            total += data.amount;
            isReceiver = 1; //reset isReceiver
        }

        //if the name is not found in any transactions
        else if ( i == (count-1) && total == 0){
            printf("ERROR: \"%s\""
                "does not contain any known transations\n", name);
        }
    } //end for

    printf("Net change for %s is %5.2f", name, total);

    return 0;
}
