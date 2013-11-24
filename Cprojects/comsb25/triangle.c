
/**
* This function computes the area and perimiter of input for a triangle.
* It reaturns values of functions by using pointers.
*
* @author Bethany Armitage
* Course: Comsb25
* Created: Sat 09/28/2013 
* Source File: triangle.c
*/

#include <math.h>
#include <stdio.h>

void triangle(double a, double b, double c, 
        double *perimiter, double *area){

	double s = (a + b + c)/2;
	*perimiter = a + b + c;
	*area = (sqrt(s*(s-a)*(s-b)*(s-c)));
	return;
}

int main(){
	double a, b, c, perimiter, area;
	puts("Enter three sides of a triangle (with decimal).");
	scanf("%lf%lf%lf", &a, &b, &c);
	triangle(a, b, c, &perimiter, &area);
	printf("Area: %f\nPerimiter: %f\n", area, perimiter);

	return 0;
}
