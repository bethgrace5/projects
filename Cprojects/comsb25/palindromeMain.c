/**
* This program contains the main for palindomresV2.c 
*
* @author Bethany Armitage
* Course: Comsb25
* Created:  Mon 11/18/2013 
* Source File: palindromeMain.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <time.h>

void readLexicon(FILE *);
void findPalindromes();

int main(int argc, char *argv[]){
    if(argc == 2){
        FILE *filePointer;
        if((filePointer = fopen(argv[1], "r"))){
            readLexicon(filePointer);
            findPalindromes();
        }
        else{
            puts("Error opening file... Exiting...");
        }
    }

    else{
        puts("Incorrect argument... Specify one filename to search...");
    }
     
    return 0;
}
