#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string_utils.h"

void replaceChar(char* s, char oldChar, char newChar) {

	if (s == NULL || oldChar == '\0' || newChar == '\0')
	{
		return;
	}

	int i;
	int n = strlen(s);

	for (i = 0; i < n; i++)
	{
		if (s[i] == oldChar)
		{
			s[i] = newChar;
		}

	}

}

char* replaceCharCopy(const char* s, char oldChar, char newChar) {

	if (s == NULL || oldChar == '\0' || newChar == '\0')
	{
		return NULL;
	}

	int i;
	int j;
	int n = strlen(s);
	char *copy = (char*) malloc(sizeof(int) * n);

	for (i = 0, j = 0; i < n; i++)
	{
		if (s[i] == oldChar)
		{
			copy[j] = newChar;
			j++;
		}
		else
		{
			copy[j] = s[i];
			j++;
		}
	}

	return copy;

}

void removeChar(char* s, char c) {

	if (s == NULL || c == '\0')
	{
		return;
	}

	int i;
	int j;
	int n = strlen(s);

	for (i = j = 0; i < n; i++)
	{
		if (s[i] != c) 
		{
			s[j] = s[i];
			j++;
		}

		s[j] = '\0';
	}

}

char* removeCharCopy(const char* s, char c) {

	if (s == NULL || c == '\0') 
	{
		return NULL;
	}

	int i;
	int j;
	int n = strlen(s);
	char* copy;

	for (i = j = 0; i < n; i++)
	{
		if (s[i] != c)
		{
			copy[j] = s[i];
			j++;
		}

		copy[j] = '\0';
	}

	return copy;

}

char** lengthSplit(const char* s, int n) {

	

}