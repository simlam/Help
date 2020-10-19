#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string_utils.h"

void replaceChar(char* s, char oldChar, char newChar) {

	char* position = strchr(s, oldChar);
	while (position) {

		*position = newChar;
		position = strchr(position, oldChar);

	}

	return;

}

char* replaceCharCopy(const char* s, char oldChar, char newChar) {

	char* copy = strchr(s, oldChar);
	while (copy) {

		*copy = newChar;
		copy = strchr(copy, oldChar);

	}

	return copy;

}

void removeChar(char* s, char c) {

	char* scan, * replace;
	for (scan = replace = s; *scan != '\0'; scan++)
	{
		*replace = *scan;
		if (*replace != c)
		{
			replace++;
		}
	}

	*replace = '\0';
	return;
}

char* removeCharCopy(const char* s, char c) {

	char* copy;
	for (s; *s!= '\0' ; s++)
	{

		if (*s != c)
		{
			*copy = *s;
			s++;
		}

	}

	return copy;

}

char** lengthSplit(const char* s, int n) {

	

}