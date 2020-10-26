char* getFileContents(const char* filePath);
/*This will gather the contents in a file as a whole string with no cuts*/

char** getFileLines(const char* filePath, int* numLines);
/*This will create an array of strings with each line of the file as an element in the array*/