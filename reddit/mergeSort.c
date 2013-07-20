#include <stdio.h>

//same as easy125(java) but written in C.

//pre-declaration
int *sort(int *toSort);

int main(int argc, char *argv[]){

int unsorted []={692, 1, 32};
int sorted []={0, 0, 0, 14, 15, 32, 123, 2431};
int i;
int len_unsorted = sizeof(unsorted)/sizeof(int);
int len_sorted = sizeof(sorted)/sizeof(int);
int (*unst)[len_unsorted] = & unsorted;
int (*st) [len_sorted]= &sorted;


printf("before sorting: \n");
for(i=0;i<len_unsorted; i++){
	printf("%d, ",unsorted[i]);
}

unst = sort(*unst);

printf("after sorting: \n");
for(i=0;i<sizeof(unsorted)/sizeof(int); i++){
	printf("%d, ",unsorted[i]);
}




printf("Unsorted contains %d elements\n",len_unsorted);
printf("Sorted contains %d elements\n",len_sorted);


int *sort(int *toSort){
int length= sizeof(toSort)/sizeof(int);
int e, temp;

for(e=0; e<length; e++){
temp=toSort[e];
	if(temp > toSort[e+1]){
	toSort[e]=toSort[e+1];
	toSort[e+1]=temp;		
}

}return toSort;
}
}
