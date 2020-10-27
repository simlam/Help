#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * A structure to model an RNA-to-Protein translation
 * Each RNA trigram is translated into a single character
 * protein
 */
typedef struct {
    char trigram[4];
    char protein;
} ProteinMap;

#define NUM_TRIGRAMS 64

/**
 * This is an array of ProteinMap elements which
 * map a trigram to a protein.  The array is presorted
 * to allow an efficient binary search.
 */
static const ProteinMap pMap[] = {
  { "AAA", 'K' },
  { "AAC", 'N' },
  { "AAG", 'K' },
  { "AAU", 'N' },
  { "ACA", 'T' },
  { "ACC", 'T' },
  { "ACG", 'T' },
  { "ACU", 'T' },
  { "AGA", 'R' },
  { "AGC", 'S' },
  { "AGG", 'R' },
  { "AGU", 'S' },
  { "AUA", 'I' },
  { "AUC", 'I' },
  { "AUG", 'M' },
  { "AUU", 'I' },
  { "CAA", 'Q' },
  { "CAC", 'H' },
  { "CAG", 'Q' },
  { "CAU", 'H' },
  { "CCA", 'P' },
  { "CCC", 'P' },
  { "CCG", 'P' },
  { "CCU", 'P' },
  { "CGA", 'R' },
  { "CGC", 'R' },
  { "CGG", 'R' },
  { "CGU", 'R' },
  { "CUA", 'L' },
  { "CUC", 'L' },
  { "CUG", 'L' },
  { "CUU", 'L' },
  { "GAA", 'E' },
  { "GAC", 'D' },
  { "GAG", 'E' },
  { "GAU", 'D' },
  { "GCA", 'A' },
  { "GCC", 'A' },
  { "GCG", 'A' },
  { "GCU", 'A' },
  { "GGA", 'G' },
  { "GGC", 'G' },
  { "GGG", 'G' },
  { "GGU", 'G' },
  { "GUA", 'V' },
  { "GUC", 'V' },
  { "GUG", 'V' },
  { "GUU", 'V' },
  { "UAA", 'x' },
  { "UAC", 'Y' },
  { "UAG", 'x' },
  { "UAU", 'Y' },
  { "UCA", 'S' },
  { "UCC", 'S' },
  { "UCG", 'S' },
  { "UCU", 'S' },
  { "UGA", 'x' },
  { "UGC", 'C' },
  { "UGG", 'W' },
  { "UGU", 'C' },
  { "UUA", 'L' },
  { "UUC", 'F' },
  { "UUG", 'L' },
  { "UUU", 'F' },
};

/**
 * An RNA-to-protein translator function.
 * The input is a string containing a valid RNA trigram
 * (a 3 character sequence consisting of A, G, C, or U)
 * The function returns a single character corresponding
 * to the translated protein.
 *
 * This function returns the null byte character, '\0' if
 * the given RNA string is invalid.
 */
char rnaToProtein(const char* rna);

/**
 * A comparator used by getProtein to perform a
 * binary search of predefined ProteinMap structures
 */
int proteinMapComp(const void* a, const void* b);

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

char rnaToProtein(const char* rna) {
    if (rna == NULL || strlen(rna) != 3) {
        return 0;
    }
    ProteinMap key = { "", '\0' };
    strcpy(key.trigram, rna);
    ProteinMap* match = bsearch(&key, pMap, NUM_TRIGRAMS, sizeof(ProteinMap), proteinMapComp);
    return (match == NULL) ? 0 : match->protein;

}

int proteinMapComp(const void* a, const void* b) {
    const ProteinMap* x = (const ProteinMap*)a;
    const ProteinMap* y = (const ProteinMap*)b;
    return strcmp(x->trigram, y->trigram);
}