#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "string_utils.h"

int main(int argc, char** argv) {

	char s[] = "abcdefg";
	int n;
	char c;
	char oldChar;
	char newChar;
	int result;

	double numPassed = 0;
	double numFailed = 0;

	/*How would I go about testing a void type function*/
	/*This tests the replace character copy function*/
	char expectedResult[] = "azcdefg";
	oldChar = 'b';
	newChar = 'z';
	printf("TESTING: replaceCharCopy(%s, %c, %c);\n", s, oldChar, newChar);
	replaceCharCopy(s, oldChar, newChar);
	result = strcmp(s, expectedResult);
	if (result == 0)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED\n");
		printf("expected result:[%s]\n", expectedResult);
		printf("replaceCharCopy result:[%s]\n", s);
		numFailed++;
	}

	char expectedResult2[] = "azcdefy";
	oldChar = 'g';
	newChar = 'y';
	printf("TESTING: replaceCharCopy(%s, %c, %c);\n", s, oldChar, newChar);
	replaceCharCopy(s, oldChar, newChar);
	result = strcmp(s, expectedResult2);
	if (result == 0)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED\n");
		printf("expected result:[%s]\n", expectedResult2);
		printf("replaceCharCopy result:[%s]\n", s);
		numFailed++;
	}

	char expectedResult3[] = "azcdafy";
	oldChar = 'e';
	newChar = 'a';
	printf("TESTING: replaceCharCopy(%s, %c, %c);\n", s, oldChar, newChar);
	replaceCharCopy(s, oldChar, newChar);
	result = strcmp(s, expectedResult3);
	if (result == 0)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED\n");
		printf("expected result:[%s]\n", expectedResult3);
		printf("replaceCharCopy result:[%s]\n", s);
		numFailed++;
	}
	printf("Number Of Test Cases Passed: %.2lf \n", numPassed);
	printf("Number Of Test Cases Failed: %.2lf \n", numFailed);
	printf("Percent Passed:				 %.2lf \n", 100 * numPassed / (numFailed + numPassed));

}