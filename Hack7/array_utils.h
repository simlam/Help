/*
This is the declaration of functions used in array_utils.c
*/

int contains(const int* arr, int size, int x);

//This functions scans through the array to determine if x is contained in the array

int containsWithin(const int* arr, int size, int x, int i, int j);

//This function scans through the array within a set bound to determine if x is contained within the bounds set in the array

int* paddedCopy(const int* arr, int oldSize, int newSize);

//This function creates a new array with a new size but keeps the values of the old array while padding every new space with 0

void reverse(int* arr, int size);

//Self explanatory, reverses the array

int* reverseCopy(const int* arr, int size);

//Again reverses the array but does it in a copy rather than the original 
