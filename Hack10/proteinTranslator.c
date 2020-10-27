#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "protein_utils.h"

void rtrim(char* str);

int main(int argc, char** argv) {

    int size = 100;
    char tempBuffer[size];
    int i = 0;
    char codon[size];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s in.txt out.txt\n", argv[0]);
        exit(1);
    }

    FILE* read = fopen(argv[1], "r");

    i = 0;
    while (fgets(tempBuffer, size, read) != NULL)
    {
        char* rna = strtok(tempBuffer, " ");
        codon[i] = rnaToProtein(rna);
        i++;
    }
    fclose(read);

    FILE* translate = fopen(argv[2], "w");
    for (i = 0; i < size; i++)
    {
        fprintf(translate, "%c", codon[i]);
    }
    fclose(translate);
    
    return 0;

}