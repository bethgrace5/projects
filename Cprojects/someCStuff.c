#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	FILE *numbers, *letters;
	/* contents of letters:(on seperate lines)
		A B C D E F G*/ 
	/* contents of numbers:(on seperate lines)
		1 2 3 4 5 6 7*/ 
//open file
	numbers = fopen("numbers.txt", "r");	
	letters = fopen("letters.txt", "r");	
//create a place to store what is read from the files
int *nextnumber ; 
char *nextletter;
int i=7;
     
//read the files.
*nextnumber = fread(nextnumber, sizeof(int), 7, numbers);
*nextletter = fread(nextletter, sizeof(int), 7, letters);
//print the files;
i=0;
for(i=0; i<8; i++){
printf("number[%d]:%13d    ",i, *nextnumber);
printf("letter[%d]:%9d\n",i, *nextletter);
};
fclose(numbers);
fclose(letters);
return 0;
}
