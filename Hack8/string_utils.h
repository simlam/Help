void replaceChar(char* s, char oldChar, char newChar);
/*This replaces the selected character with a new character of choice*/

char* replaceCharCopy(const char* s, char oldChar, char newChar);
/*This does the same as replaceChar but does so in a copy*/

void removeChar(char* s, char c);
/*This does what the function name says and removes a specified character in the string*/

char* removeCharCopy(const char* s, char c);
/*Does what removeChar states but does so in a copy*/

char** lengthSplit(const char* s, int n);
/*Takes a string and splits it in n amount of length*/