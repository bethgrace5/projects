#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	FILE *numbers;
	/* contents of letters:(on seperate lines)
		A B C D E F G*/ 
	/* contents of numbers:(on seperate lines)
		1 2 3 4 5 6 7*/ 
//open file
	numbers = fopen("numbers.txt", "r");	
//create a place to store what is read from the files
int nextnumber[7];
//print the files.
fread(nextnumber, sizeof(int), 7, numbers);
int i=0;
for(i=0; i<8; i++){
printf("%d\n",nextnumber[i]);
};
fclose(numbers);
return 0;
}
