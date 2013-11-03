/**
* This program contains readLexicon(),  reverseWord(), and findPalindromes().
*
* @author Bethany Armitage
* Course: Comsb25
* Created: Tue 10/29/2013 
* Source File: palindromes.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE_WORD 32
#define NUM_WORDS_IN_LEXICON 172823

static int numWords = 0;
static char lexicon[NUM_WORDS_IN_LEXICON + 1][MAX_SIZE_WORD];

/**
* This function reads a list of words one perline, into lexicon, the static
* global array of strings. This function also sets the static global 
* variable numWords, which will be used by findPalindromes().
*/
void readLexicon(void){
	int i, j;
	for(i=0; i<NUM_WORDS_IN_LEXICON; i++){
		scanf("%s", lexicon[i]);
		//checking to remove whitespace and replace with null terminator
		for(j=0; j<MAX_SIZE_WORD; j++){
			if (lexicon[i][j]=='\0'|| lexicon[i][j]=='\n'){
				lexicon[i][j]= '\0';
				break;
			}
		}
	}
	return;
}

/**
* This function reverses word and puts it in reverseWord. 
* @param: word- pointer to string
* @param: reverseWord- pointer to string for reverse of word.
*/
void reverseWord(char *word, char *reverseWord){
	int k, t;
	for(k=0,t=strlen(word); k<strlen(word) || t>= 0 ; k++, t--){
		reverseWord[k] = word[t-1];
	}
	return;
}

/**
* This function checks every word in lexicon for palindromicity by calling
* reverse word() and comparing the reversed word with the original word
* to see if they are the same, using strcmp(). this function prints out
* palindromes it finds.
*/
void findPalindromes(void){
	int n;
	char reverse[MAX_SIZE_WORD];
	for(n=0; n<NUM_WORDS_IN_LEXICON; n++){
		reverseWord(lexicon[n], reverse);
		if(strcmp(lexicon[n], reverse) == 0 ){
			puts(reverse);
			numWords++;
		}
	}	
	return;
}
