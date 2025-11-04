#include <stdio.h>
//scriviamo un programma che conta i caratteri in un file più ottimizzato rispetto a file4.c (in cui si usavano le funzioni per file binari)
void main() {
    int i = 0;
    FILE *fp = fopen("file da contare righe.txt", "r");
    if (fp == NULL) printf("Err 1\n");
    else {
        while (fgetc(fp) != EOF) i++;
        fclose(fp);

        printf("ci sono %d caratteri nel file\n", i);
    }
}