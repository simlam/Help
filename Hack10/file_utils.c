#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_utils.h"

char* getFileContents(const char* filePath) {

	int size = 100;
	char tempBuffer[size];
	char* stringcopy;

	FILE* read = fopen(filePath, "r");
	if (read == NULL)
	{
		return NULL;
	}

	fgets(tempBuffer, size, read);
	strcpy(stringcopy, tempBuffer);
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
		char* lineToken = strtok(tempBuffer, '\n');
		strcpy(strings[i], lineToken);
		i++;
	}

	fclose(read);
	return strings;

}