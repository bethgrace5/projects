#include <stdio.h>

/*
 * This program reads 100 doubles from stdin into an array and
 * then prints out the minimum and maximum values.
 *
 * @author: Bethany Armitage	
 * Course:  COMS B25
 * Created: Sun 10/06/2013 
 * Source File:   minmax.c
 */

/*
 * This function returns pointers to the minimum and
 * maximum values in an array of doubles with size elements.
 *
 * @param array array of doubles
 * @param size number of elements
 * @param min pointer to a pointer to the minimum value in the array
 * @param max pointer to a pointer to the maximum value in the array 
 */
void minmax(double array[], const int size, double **min, double **max) {
	int i;
	*min = &array[0];
	*max = &array[0];
	
	for(i=0; i<size; i++){
		if(array[i] < **min){
			*min = &array[i];
		}
		if(array[i] > **max){
			*max = &array[i];
		}
	}
	return;
}

/*
 * This function reads size doubles from stdin into array.
 *
 * @param array array of doubles
 * @param size number of elements in array
 */
void readDoubles(double *array, int size) {
	while(size > 0){
		scanf("%lf", array);
		array ++;
		size--;
	}
	return;
}

int main() {
	const int size = 100;
	double *min, *max;
	double array[size];
	
	readDoubles(array, size);
	minmax(array, size, &min, &max);
	printf("Minimum value = %f, Maximum = %f\n", *min, *max);

	return 0;
}
