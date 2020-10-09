#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "array_utils.h"

int dotProduct(const int* a, const int* b, int n, int* result) {

	//Error check

	if (a == NULL || b == NULL || n < 0 || result == NULL)
	{
		return 1;
	}
	else 
	{
		int i;
		int prod = 0;

		for (i = 0; i < n; i++)
		{
			ap[i] = a[i];
			bp[i] = b[i];
			prod += ap[i] * bp[i];
		}
		*result = prod;
	}
	return 0;
}

int biasedDotProduct(const int* a, const int* b, int n, int* result) {

	//Error check

	if (a == NULL || b == NULL || n < 0 || result == NULL)
	{
		return 1;
	}
	else
	{
		int i;
		int prod = 0;
		int biasedprod = 0;

		for (i = 0; i < n; i++)
		{
			prod = ap[i] * bp[i];
			if (prod >= 0)
			{
				biasedprod += prod;
			}
		}
		*result = biasedprod;
	}
	return 0;
}

int* filterPositive(const int* arr, int n, int* newSize) {

	//Error check

	if (arr == NULL || n < 1 || newSize == NULL)
	{
		return NULL;
	}
	else
	{
		//Initialize new pointer array 

		int* newArr = (int*)malloc(n * (sizeof(int)));

		//i is used to track input array
		//j is used to track output array
		//new is a counter for the new size of the output array

		int i,
			j = 0,
			new = 0;

		//We use a for loop with counters for the newArr in j and new
		//Variable j keeps track of the element in newArr so that during a fail of condition newArr will not input anything in that slot but reserve it for the next condition pass
		//Variable new tracks the size of newArr and also only goes up by one count during a pass

		for (i = 0; i < n; i++)
		{
			if (arr[i] > 0)
			{
				newArr[j] = arr[i];
				new++;
				j++;
			}
		}
		*newSize = new;
		return newArr;
	}
}