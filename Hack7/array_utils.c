#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "array_utils.h"

int contains(const int* arr, int size, int x) {

	int i;
	int flag = 0;

	for (i = 0; i < size; i++)
	{
		if (arr[i] == x) 
		{
			flag = 1;
		}
	}

	if (flag == 1)
	{
		printf("TRUE");
	}
	else
	{
		printf("FALSE");
	}

	return 0;

}

int containsWithin(const int* arr, int size, int x, int i, int j) {

	int k;
	int flag = 0; 

	if (j > size)
	{
		j == size;
	}

	for (k = i - 1; k <= j - 1 ; k++)
	{

		if (arr[k] == x)
		{
			flag = 1;
		}

	}

	if (flag == 1)
	{
		printf("TRUE");
	}
	else
	{
		printf("FALSE");
	}

	return 0;

}

int* paddedCopy(const int* arr, int oldSize, int newSize) {

	int i;
	int j;
	int newArr[newSize];

	if (newSize < oldSize)
	{
		printf("[ ");
		for (i = 0; i < newSize; i++)
		{

			newArr[i] = arr[i];
			printf("%d ", newArr[i]);

		}

		printf("]");
		return 0;

	}

	printf("[ ");

	for (i = 0; i < oldSize; i++) {

		newArr[i] = arr[i];
		printf("%d ", newArr[i]);

	}

	for (j = oldSize; j < newSize; j++)
	{
		newArr[j] = 0;
		printf("%d ", newArr[j]);
	}

	printf("]");
	
	return 0;

}

void reverse(int* arr, int size) {

	int i;
	int j;
	int newArr[size];

	printf("[ ");

	for (i = 0, j = size - 1; i < size; i++, j--)
	{
		
		newArr[i] = arr[j];
		printf("%d ", newArr[i]);

	}

	printf("]");

}

int* reverseCopy(const int* arr, int size) {

	int i;
	int j;
	int k;
	int newArr[size];

	printf("Copy\n");
	printf("[ ");

	for (j = 0; j < size; j++)
	{

		printf("%d ", arr[j]);

	}

	printf("]\n");

	printf("Reverse copy\n");
	printf("[ ");

	for (i = 0, k = size - 1; i < size; i++, k--)
	{

		newArr[i] = arr[k];
		printf("%d ", newArr[i]);

	}

	printf("]");

	return 0;

}