#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_utils.h"

char* getFileContents(const char* filePath) {

	int const size = 500;
	char tempBuffer[size];

	FILE* read = fopen(filePath, "r");
	if (read == NULL)
	{
		fprintf(stderr, "Unable to open file: %s\n", filePath);
		return NULL;
	}

	char* string = fgets(tempBuffer, size, read);
	fclose(read);
	return string;

}

char** getFileLines(const char* filePath, int* numLines) {

	int const size = 500;
	char tempBuffer[size];
	int i = 0;
	int n;
	n = *numLines;
	
	char** strings = (char**)malloc(sizeof(char*) * n);

	FILE* read = fopen(filePath, "r");
	if (read == NULL)
	{
		fprintf(stderr, "Unable to open file: %s\n", filePath);
		return NULL;
	}
	if (numLines == NULL)
	{
		return NULL;
	}

	while (fgets(tempBuffer, size, read) != NULL)
	{
		tempBuffer[strlen(tempBuffer) - 1] = '\0';
		char* lineToken = strtok(tempBuffer, "\n");
		strcpy(strings[i], lineToken);
		i++;
	}

	fclose(read);
	return strings;

}