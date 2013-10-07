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
 * @param size number of elements in array
 * @param min pointer to a pointer which should point to the minimum value
 *          in the array upon function return 
 * @param max pointer to a pointer which should point to the maximum value
 *          in the array upon function return 
 */
void minmax(double array[], const int size, double **min, double ** max) {

}

/*
 * This function reads size doubles from stdin into array.
 *
 * @param array array of doubles
 * @param size number of elements in array
 */
void readDoubles(double *array, int size) {
	// Replace this comment with your code 
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
