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

	for (i = 0, j = 0; i < n; i++, j++)
	{
		if (s[i] == oldChar)
		{
			copy[j] = newChar;
		}
		else
		{
			copy[j] = s[i];
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

	int i;
	int j;

	int x = strlen(s);

	char** copy;

	if ((x % n) == 0) 
	{
		copy = (char**)malloc(sizeof(char*) * (x / n));

		for (i = 0; i < (x / n); i++) 
		{
			copy[i] = (char*)malloc(sizeof(char) * n);
		}

		for (i = 0; i < (x / n); i++) 
		{
			for (j = 0; j < n; j++) 
			{
				copy[i][j] = s[(i * n) + j]; 
			}
		}
	}

	else 
	{
		copy = (char**)malloc(sizeof(char) * ((x / n) + 1));

		for (i = 0; i < ((x / n) + 1); i++) 
		{
			copy[i] = (char*)malloc(sizeof(char) * n);
		}

		for (i = 0; i < ((x / n) + 1); i++)
		{
			for (j = 0; j < n; j++) 
			{
				if (((i * n) + j) >= x) 
				{
					copy[i][j] = ' ';
				}

				else
				{
					copy[i][j] = s[(i * n) + j];
				}
			}
		}
	}

	return copy;

}
