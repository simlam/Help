#include<stdio.h>
#include<stdlib.h>

#include "protein_utils.h"

void rtrim(char* str); 

int main(int argc, char** argv) {

    int size = 500;
    char tempBuffer[size];
    int i;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s in.txt out.txt\n", argv[0]);
        exit(1);
    }

    FILE* read = fopen(argv[1], "r");
    char protein = rnaToProtein(tempBuffer);
    fclose(read);

    FILE* translate = fopen(argv[2], "w");
    fprintf(translate, "%s", protein);
    fclose(translate);
    
    return 0;

}
