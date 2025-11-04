#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 200

//
struct MyStruct {
    char rigo[NMAX];  //righe del file input.txt
    int len_riga;    //lunghezza di ogni rigo del file
};

int main() {
    FILE *fp;
    char s[NMAX];
    char *ps;
    struct MyStruct vet_struct[NMAX];
    int n = 0;


    fp = fopen("file1/input.txt", "r");
    if (fp != NULL) {
        do {
            ps = fgets(s, NMAX, fp);
            if (ps != NULL) {
                printf("%s", s);
                vet_struct[n].len_riga = strlen(s);
                strcpy(vet_struct[n].rigo, s);  //copiamo la riga nel campo rigo dell'ennesima struct 
                n++;  //numero di righe
            }
        } while (ps != NULL);   //fin quando il file non è concluso
        fclose(fp);


        fp = fopen("file1/output.bin", "w");
        if (fp != NULL) {//salviamo in un file binario la struct contenente le righe in stringhe e il numero di righe
            fwrite(vet_struct, sizeof(struct MyStruct), n, fp);
            fclose(fp);
        }
        else printf("ERR file output.bin");
    }
    else printf("ERR file input.txt");
}