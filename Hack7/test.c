#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "array_utils.h"

int main() {

	int func;
	int size;
	int x;
	int i;
	int j;
	int oldSize;
	int newSize;

	printf("Enter size of array: ");
	scanf("%d", &size);

	int arr[size];

	for (i = 0; i < size; i++)
	{
		printf("enter %dth element of array: ", i);
		scanf("%d", &arr[i]);
	}

	printf("Enter operation: \n");
	printf("1: contains\n2: contains within bound\n3: copy and pad\n4: reverse array\n5: copy and reverse\n");
	scanf("%d", &func);

	switch (func)
	{
	case 1:

		printf("Enter value to search: ");
		scanf("%d", &x);

		contains(arr, size, x);

		break;

	case 2:

		printf("Enter value to search: ");
		scanf("%d", &x);
		printf("Enter lower bound: ");
		scanf("%d", &i);
		printf("Enter upper bound: ");
		scanf("%d", &j);

		containsWithin(arr, size, x, i, j);

		break;

	case 3:

		printf("Enter new size: ");
		scanf("%d", &newSize);

		paddedCopy(arr, size, newSize);

		break;

	case 4:

		printf("This is the reverse of the array.\n");

		reverse(arr, size);

		break;

	case 5:

		printf("This is a reverse of the array and a copy of original.\n");

		reverseCopy(arr, size);

		break;

	default:

		printf("Enter valid response");

		break;

	}

	return 0;

}