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
int nextnumber[7];
char nextletter[7];
//read the files.
fread(nextnumber, sizeof(int), 7, numbers);
fread(nextletter, sizeof(int), 7, letters);
//print the files;
int i=0;
for(i=0; i<8; i++){
printf("number[%d]:%d\n",i,(int) nextnumber[i]);
printf("letter[%d]:%d\n",i,(char) nextletter[i]);
};
fclose(numbers);
fclose(letters);
return 0;
}
