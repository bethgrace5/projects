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
for(i=0;i<len_unsorted; i++){
	printf("%d, \n",*unst[i]);
}
//sorting unsorted here
for(i=0; i<len_unsorted; i++){
temp = unsorted[i];
position = i;
	if(temp < unsorted[i]){
	temp = unsorted[i];
	}
	*ret_array[len_unsorted-i-1] = temp;
	unsorted[position]=0;
}

	printf("after sorting: \n");
for(e=0;e<(len_unsorted); e++){
	printf("%d, \n",*ret_array[e]);
}
//will merge the two lists here.



printf("after merging: \n");
for(i=0;i<len_unsorted+len_sorted; i++){
	printf("%d, ",*unst[i]);
}


printf("Unsorted contains %d elements\n",len_unsorted);
printf("Sorted contains %d elements\n",len_sorted);


}
