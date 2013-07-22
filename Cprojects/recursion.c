#include<stdio.h>
//tests how many times a method will loop until crash.
int counter=0;
int recursion(){
	++counter;
	printf("%d\n", counter);
	recursion();
	return 0;
};

int main(){

	recursion();
	return 0;
}
/*max value of counter different each time program is executed.
(prints 'segmentation fault' directly after)
261,745
261,717
261,758
261,901
261,912
261,727
261,944
261,816
261,876
261,923	*/
