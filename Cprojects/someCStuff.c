#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	FILE *letters, *numbers, *concatenation;
	/* contents of letters:(on seperate lines)
		A B C D E F G*/ 
	/* contents of numbers:(on seperate lines)
		1 2 3 4 5 6 7*/ 
//open files
	letters = fopen("letters.txt", "r");	
	numbers = fopen("numbers.txt", "r");	
	concatenation = fopen("concatenation.txt", "w");	
//create a place to store what is read from the files
char nextletter[7];
int nextnumber;
//print the files.
while(fscanf(*letters, "%d", *nextletter)==1){
	printf(*letters, "%s\n", *nextletter);
}
while(fscanf(*numbers, "%d", *nextnumber)==1){
	printf(*numbers, "%d\n", *nextnumber);
}
//will create a concatenation of the two files in a new file.
//after I read the files successfully...
return 0;
}
