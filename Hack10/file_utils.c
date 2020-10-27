#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_utils.h"

char* getFileContents(const char* filePath) {

	char* stringcopy[100];

	FILE* read = fopen(filePath, "r");
	if (read == NULL)
	{
		return NULL;
	}

	fscanf(read, "%s", stringcopy);
	fclose(read);

	return stringcopy;

}

char** getFileLines(const char* filePath, int* numLines) {

	int n;
	n = *numLines;
	char tempBuffer[n];
	int i = 0;

	
	char** strings = (char**)malloc(sizeof(char*) * n);

	FILE* read = fopen(filePath, "r");
	if (read == NULL)
	{
		return NULL;
	}
	if (numLines == NULL)
	{
		return NULL;
	}

	while (fgets(tempBuffer, n, read) != NULL)
	{
		tempBuffer[strlen(tempBuffer) - 1] = '\0';
		strcpy(strings[i], tempBuffer);
		i++;
	}

	fclose(read);
	return strings;

}