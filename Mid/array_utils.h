//This is a header file for the array_utils.c

int dotProduct(const int* a, const int* b, int n, int* result);
//This function calculates the dot product of two pointer arrays with size n

int biasedDotProduct(const int* a, const int* b, int n, int* result);
//This function calculates the biased dot product of two pointer arrays with size n

int* filterPositive(const int* arr, int n, int* newSize);
//This function takes an array and outputs the positive values of the array only

