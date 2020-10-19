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

	/*The fact that the pointer functions work then the void version of the function will be successful as well*/
	/*How would I go about testing a void type function*/
	/*This tests the replace character copy function*/
	char expectedResult[] = "azcdefg";
	oldChar = 'b';
	newChar = 'z';
	printf("TESTING: replaceCharCopy(%s, %c, %c);\n", s, oldChar, newChar);
	char *new = replaceCharCopy(s, oldChar, newChar);
	result = strcmp(new, expectedResult);
	if (result == 0)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED\n");
		printf("expected result:[%s]\n", expectedResult);
		printf("replaceCharCopy result:[%s]\n", new);
		numFailed++;
	}

	char expectedResult2[] = "abcdefy";
	oldChar = 'g';
	newChar = 'y';
	printf("TESTING: replaceCharCopy(%s, %c, %c);\n", s, oldChar, newChar);
	new = replaceCharCopy(s, oldChar, newChar);
	result = strcmp(new, expectedResult2);
	if (result == 0)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED\n");
		printf("expected result:[%s]\n", expectedResult2);
		printf("replaceCharCopy result:[%s]\n", new);
		numFailed++;
	}

	char expectedResult3[] = "abcdafg";
	oldChar = 'e';
	newChar = 'a';
	printf("TESTING: replaceCharCopy(%s, %c, %c);\n", s, oldChar, newChar);
	new = replaceCharCopy(s, oldChar, newChar);
	result = strcmp(new, expectedResult3);
	if (result == 0)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED\n");
		printf("expected result:[%s]\n", expectedResult3);
		printf("replaceCharCopy result:[%s]\n", new);
		numFailed++;
	}

	/*Testing removeCharCopy*/
	/*Again how would I go about testing the void function*/

	char expectedResult4[] = "acdefg";
	c = 'b';
	printf("TESTING: removeCharCopy(%s, %c);\n", s, c);
	new = removeCharCopy(s, c);
	result = strcmp(new, expectedResult4);
	if (result == 0)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED\n");
		printf("expected result:[%s]\n", expectedResult4);
		printf("removeCharCopy result:[%s]\n", new);
		numFailed++;
	}

	char expectedResult5[] = "bcdefg";
	c = 'a';
	printf("TESTING: removeCharCopy(%s, %c);\n", s, c);
	new = removeCharCopy(s, c);
	result = strcmp(new, expectedResult5);
	if (result == 0)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED\n");
		printf("expected result:[%s]\n", expectedResult5);
		printf("removeCharCopy result:[%s]\n", new);
		numFailed++;
	}

	char expectedResult6[] = "abcdef";
	c = 'g';
	printf("TESTING: removeCharCopy(%s, %c);\n", s, c);
	new = removeCharCopy(s, c);
	result = strcmp(new, expectedResult6);
	if (result == 0)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED\n");
		printf("expected result:[%s]\n", expectedResult6);
		printf("removeCharCopy result:[%s]\n", new);
		numFailed++;
	}

	/*This is a test of lengthSplit*/

	n = 4;
	char **new1 = lengthSplit(s, n);
	printf("[%s]\n", new1);


	printf("Number Of Test Cases Passed: %.2lf \n", numPassed);
	printf("Number Of Test Cases Failed: %.2lf \n", numFailed);
	printf("Percent Passed:				 %.2lf \n", 100 * numPassed / (numFailed + numPassed));

}