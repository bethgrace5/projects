#include <stdio.h>

//same as easy125(java) but written in C.

//pre-declaration
int *sort(int *toSort);
int *merge(int *one, int *two);

int main(int argc, char *argv[]){

int unsorted []={692, 1, 32};
int sorted []={0, 0, 0, 14, 15, 32, 123, 2431};
int i;
int len_unsorted = sizeof(unsorted)/sizeof(int);
int len_sorted = sizeof(sorted)/sizeof(int);
int mergedList [len_unsorted + len_sorted];
int (*unst)[len_unsorted];
int (*st) [len_sorted];
int (*mrgd)[sizeof(mergedList)];

printf("before sorting: \n");
for(i=0;i<len_unsorted; i++){
	printf("%d, ",unsorted[i]);
}
// "error: lvalue required as unary '&' operand"
unst = &(sort(*unst));

printf("after sorting: \n");
for(i=0;i<sizeof(unsorted)/sizeof(int); i++){
	printf("%d, ",unsorted[i]);
}

// "error: lvalue required as unary '&' operand"
mrgd = &(merge(*unst, *st));
printf("after merging: \n");
for(i=0;i<sizeof(unsorted)/sizeof(int); i++){
	printf("%d, ",unsorted[i]);
}




//testing values for length of unsorted and sorted.
printf("Unsorted contains %d elements\n",len_unsorted);
printf("Sorted contains %d elements\n",len_sorted);

//I realize just how much Java spoiled me with ArrayLists...
//this function should return a pointer
int *sort(int *toSort){
int (*ret_array)[len_unsorted];
int e, temp, position;
for(i=0; i<len_unsorted; i++){
temp = toSort[i];
position = i;
	for(e=0; e<len_unsorted; e++){
	if(temp < toSort[e]){
	temp = toSort[e];
	position = e;	
	--i;
	}
	temp = *ret_array[len_unsorted-i-1];
	toSort[position]=0;
	return *ret_array;
}
}
	*ret_array[i]=temp;
	

return toSort;
}
int *merge(int *one, int *two){
//TODO:merge two sorted lists here.

}
}
