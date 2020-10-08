#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "array_utils.h"
/* This is a convenience function that prints an integer * array to the standard output.*/
void printIntArray(const int *arr, int n);
int main(int argc, char **argv) { 
	int n = 5, m;  
	int a[] = {-2, 5, 3, 2, 1};  
	int b[] = {9, 4, 8, 0, -2};  
	int *c = NULL;  
	int x;  dotProduct(a, b, n, &x);  
	printf("dot product = %d\n", x); 
	biasedDotProduct(a, b, n, &x);  
	printf("biased dot product = %d\n", x);  
	c = filterPositive(a, n, &m);  
	printf("filter of a: ");  
	printIntArray(c, m);  
	return 0;}
void printIntArray(const int *arr, int n) {  
	printf("[");   
	for(int i=0; i<n-1; i++) {    
		printf("%d, ", arr[i]);  
	}  
	printf("%d]\n", arr[n-1]); }