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
	char *new2 = replaceCharCopy(s, oldChar, newChar);
	result = strcmp(new2, expectedResult2);
	if (result == 0)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED\n");
		printf("expected result:[%s]\n", expectedResult2);
		printf("replaceCharCopy result:[%s]\n", new2);
		numFailed++;
	}

	char expectedResult3[] = "abcdafg";
	oldChar = 'e';
	newChar = 'a';
	printf("TESTING: replaceCharCopy(%s, %c, %c);\n", s, oldChar, newChar);
	char *new3 = replaceCharCopy(s, oldChar, newChar);
	result = strcmp(new3, expectedResult3);
	if (result == 0)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED\n");
		printf("expected result:[%s]\n", expectedResult3);
		printf("replaceCharCopy result:[%s]\n", new3);
		numFailed++;
	}

	/*Testing removeCharCopy*/
	/*Again how would I go about testing the void function*/

	char expectedResult4[] = "acdefg";
	c = 'b';
	printf("TESTING: removeCharCopy(%s, %c);\n", s, c);
	char *copy = removeCharCopy(s, c);
	result = strcmp(copy, expectedResult4);
	if (result == 0)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED\n");
		printf("expected result:[%s]\n", expectedResult4);
		printf("removeCharCopy result:[%s]\n", copy);
		numFailed++;
	}

	char expectedResult5[] = "bcdefg";
	c = 'a';
	printf("TESTING: removeCharCopy(%s, %c);\n", s, c);
	char *copy2 = removeCharCopy(s, c);
	result = strcmp(copy2, expectedResult5);
	if (result == 0)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED\n");
		printf("expected result:[%s]\n", expectedResult5);
		printf("removeCharCopy result:[%s]\n", copy2);
		numFailed++;
	}

	char expectedResult6[] = "abcdef";
	c = 'g';
	printf("TESTING: removeCharCopy(%s, %c);\n", s, c);
	char *copy3 = removeCharCopy(s, c);
	result = strcmp(copy3, expectedResult6);
	if (result == 0)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED\n");
		printf("expected result:[%s]\n", expectedResult6);
		printf("removeCharCopy result:[%s]\n", copy3);
		numFailed++;
	}


	printf("Number Of Test Cases Passed: %.2lf \n", numPassed);
	printf("Number Of Test Cases Failed: %.2lf \n", numFailed);
	printf("Percent Passed:				 %.2lf \n", 100 * numPassed / (numFailed + numPassed));

}