#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "array_utils.h"

int contains(const int* arr, int size, int x) {

	int i;
	int flag = 0;

	//Keep in mind when referencing an item in an array it begins at 0 
	//i.e. int arr[5] = { 1, 2, 3, 4, 5, }
	//arr[0] = 1, arr[1] = 2, arr[2] = 3 ... arr[4] = 5
	//When declaring the array the number in brackets reference amount of items within
	//When reading/writing/looking for an item in the array the number in bracket references the element in array 

	//Use flag to set off trigger when number is found
	//Use loop to scan through each number in the array one by one

	for (i = 0; i < size; i++)
	{
		if (arr[i] == x) 
		{
			flag = 1;
		}
	}

	if (flag == 1)
	{
		return 0;
	}
	else
	{
		return 1;
	}

	return 0;

}

//We use the same flag system but set bounds with i and j 
//Since we are reading/writing/looking for an item in the array with a set bound, we set a more standard way of thinking
//Because the first element of an array is referenced with 0, we subtract 1 to both sides of the bounds to shift the first element up 1
//i.e. We go from thinking 0 as first element to 1 as first element 

int containsWithin(const int* arr, int size, int x, int i, int j) {

	int k;
	int flag = 0; 

	if (j > size)
	{
		j = size;
	}

	for (k = i; k <= j ; k++)
	{

		if (arr[k] == x)
		{
			flag = 1;
		}

	}

	if (flag == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}

	return 0;

}

//This uses a new array to create the desired size
//We do a check to see if the new size desired is less than the old
//If the new size is less than the old we only input up to the amount specified with the new size
//If the new size is more than the old then we output all of the original array and all the leftover space is = 0
//This also teaches you that you can set an array item equal to another item in another array
//Keep in mind that it is overwritten however and the old value is lost
//When adding 0 to pad out the new array size we start from the end of the old size and move up to the new size
//That's why we have two for loops if the size check fails

int* paddedCopy(const int* arr, int oldSize, int newSize) {

	int i;
	int j;
	int m = newSize;
	int* newArr = (int*)malloc(sizeof(int) * m);

	if (newSize < oldSize)
	{
		/*printf("[ ");*/
		for (i = 0; i < newSize; i++)
		{

			newArr[i] = arr[i];
			/*printf("%d ", newArr[i]);*/

		}

		/*printf("]");
		return 0;*/

	}

	/*printf("[ ");*/

	for (i = 0; i < oldSize; i++) {

		newArr[i] = arr[i];
		/*printf("%d ", newArr[i]);*/

	}

	for (j = oldSize; j < newSize; j++)
	{
		newArr[j] = 0;
		/*printf("%d ", newArr[j]);*/
	}

	/*printf("]");*/
	free(newArr);
	
	return 0;

}

//This is self explanatory
//We have a for loop with two conditions: one going up and another going down
//The one going up is the new array and the one going down is the end of the old array decreasing incrementaly 
//Doing this flips the order of the old array into a new one 
//Again we have to also think in terms of elements in array and not just how many is in the array
//This is why we subtract 1 from the size to accomodate for the first element when referenced is = 0 and not 1 
//i.e. element |0|1|2|3|4|5|
//     value   |1|2|3|4|5|6|
//In this array the size is 6 but the element count only goes up to 5

void reverse(int* arr, int size) {

	int i;
	int j;
	int m = size;
	int* newArr = (int*)malloc(sizeof(int) * m);

	/*printf("[ ");*/

	for (i = 0, j = size - 1; i < size; i++, j--)
	{
		
		newArr[i] = arr[j];
		/*printf("%d ", newArr[i]);*/

	}

	/*printf("]");*/

	free(newArr);

	return;

}

//This combines everything we did so far and puts it together basically
//This takes the original array and straight up spits it back out with a for loop
//Then it takes the original array and makes another copy that spits out the reverse like we did previously

int* reverseCopy(const int* arr, int size) {

	int i;
	int j;
	int k;
	int m = size;
	int* newArr = (int*)malloc(sizeof(int) * m);
	int* copyArr = (int*)malloc(sizeof(int) * m);

	/*printf("Copy\n");
	printf("[ ");*/

	for (j = 0; j < size; j++)
	{

		/*printf("%d ", arr[j]);*/
		copyArr[j] = arr[j];

	}
	
	/*printf("]\n");

	printf("Reverse copy\n");
	printf("[ ");*/

	for (i = 0, k = size - 1; i < size; i++, k--)
	{

		newArr[i] = arr[k];
		/*printf("%d ", newArr[i]);*/

	}

	/*printf("]");*/
	free(copyArr);
	free(newArr);

	return 0;

}