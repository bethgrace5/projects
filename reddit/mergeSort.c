#include <stdio.h>

//same as easy125(java) but written in C.

//pre-declaration

int main(int argc, char *argv[]){

int unsorted []={692, 1, 32};
int sorted []={0, 0, 0, 14, 15, 32, 123, 2431};
int i, e, temp, position;
int len_unsorted = sizeof(unsorted)/sizeof(int);
int len_sorted = sizeof(sorted)/sizeof(int);
int mergedList [len_unsorted + len_sorted];
int returnarray [len_unsorted];
int (*unst)[len_unsorted] = &unsorted;
int (*st) [len_sorted] = &sorted;
int (*mrgd)[sizeof(mergedList)];
int (*ret_array)[len_unsorted]= &returnarray;

	printf("before sorting: \n");
for(i=0;i<(len_unsorted); i++){
	printf("%d, \n",unsorted[i]);
}
//Here's my sorting idea.
//Find largest in unsorted. Set bottom of return array to value 
//Change that value to 0 in unsorted. Repeat.
for(i=0; i<(len_unsorted); i++){
temp = unsorted[i];
position = i;
for(e=0; e<len_unsorted; e++){
	if(temp < unsorted[e]){
	temp = unsorted[e];
	position = e;
	
	}
//trying to put the last nonzero element (smallest number)into returnarray[0];
	if((i== len_unsorted-1) && (unsorted[e]< temp)){
	returnarray[0] = unsorted[e];
	}
	returnarray[len_unsorted-i-1] = temp;
	unsorted[position]=0;
}
}

	printf("after sorting: \n");
for(e=0;e<(len_unsorted); e++){
	printf("%d, \n",returnarray[e]);
}
//will merge the two lists here.



printf("after merging: \n");
for(i=0;i<len_unsorted+len_sorted; i++){
	printf("%d, ",*unst[i]);
}


printf("Unsorted contains %d elements\n",len_unsorted);
printf("Sorted contains %d elements\n",len_sorted);


}
