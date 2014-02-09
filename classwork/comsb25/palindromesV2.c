
/**
* This program contains readLexicon(),reverseWord(), and findPalindromes().
* @author Bethany Armitage
* Course: Comsb25
* Created: Mon 11/18/2013 
* Source File: palindromesV2.c 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE_WORD 32

static int numWords = 0;
static char **lexicon;
char *nextWord;

/**
* This function reads a list of words one perline, into lexicon, the static
* global array of strings. This function also sets the static global 
* variable numWords, which will be used by findPalindromes().
*/
void readLexicon(FILE *fp){
    int i;
    nextWord = malloc(sizeof(char)*MAX_SIZE_WORD);

    //count number of words
	while(fscanf(fp, "%s", nextWord) != EOF)
        numWords++;

    //reset file pointer
    fseek(fp, 0, SEEK_SET);

    lexicon = malloc(sizeof(char*)*numWords);
    
    //store words in lexicon
    for(i=0; i<numWords; i++){
        fscanf(fp, "%s", nextWord);
        *(lexicon+i) = malloc(sizeof(char) * strlen(nextWord));
        lexicon[i] = nextWord;

        //without reallocating nextWord, only the last word 
        //was stored in every spot of lexicon
        nextWord = realloc(NULL, sizeof(char)*MAX_SIZE_WORD);
    }
    printf("\nwords read:%d\n\n",numWords);
	return;
}

/**
* This function reverses word and puts it in reverseWord. 
* @param: word- pointer to string
* @param: reverseWord- pointer to string for reverse of word.
*/
void reverseWord(char *word, char *reverseWord){
	int k,t;
    int length = strlen(word);

	for(k=0, t=strlen(word); k<length || t>0 ; k++, t--)
		reverseWord[k] = word[t-1];

	return;
}

/**
* This function checks every word in lexicon for palindromicity by calling
* reverse word() and comparing the reversed word with the original word
* to see if they are the same, using strcmp(). this function prints out
* palindromes it finds.
*/
void findPalindromes(){
    int n;
	for(n=0; n<numWords; n++){
        char *reverse = malloc(sizeof(char)*MAX_SIZE_WORD);
		reverseWord(lexicon[n], reverse);

		if(strcmp(lexicon[n], reverse) == 0){
			puts(reverse);
		}
	}	
	return;
}
