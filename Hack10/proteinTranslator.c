#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "protein_utils.h"

void rtrim(char* str);

int main(int argc, char** argv) {

    int size = 100;
    char tempBuffer[size];
    char* protein;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s in.txt out.txt\n", argv[0]);
        exit(1);
    }

    FILE* read = fopen(argv[1], "r");
    fgets(tempBuffer, size, read);
    protein = rnaToProtein(tempBuffer);
    rtrim(protein);
    fclose(read);

    FILE* translate = fopen(argv[2], "w");
    fprintf(translate, "%s", protein);
    fclose(translate);
    
    return 0;

}

void rtrim(char* str) {
    int n = strlen(str);
    while (n >= 0 && isspace(str[n - 1])) {
        str[n - 1] = '\0';
        n--;
    }
    return;
}
