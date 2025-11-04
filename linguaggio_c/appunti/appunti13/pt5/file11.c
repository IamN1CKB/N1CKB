#include <stdio.h>
void main(){
    /*
    esistono anche delle funzioni per gestire solo un carattere in un file
    esse sono fgetc() e fputc()
    */
    char c = 'A', x;
    FILE *fp = fopen("file di testo.txt", "w");
    if (fp == NULL) printf("errore 1\n");
    else {
        fputc(c, fp);  //inserisce solo c nel file

        printf("scrivi un carattere: ");
        scanf("%c", &c);
        fputc(c, fp);  //inserisce il carattere scritto dall'utente nel file
        fclose(fp);
    }

    fp = fopen("file di testo.txt", "r");   //riapro il file in lettura
    if (fp == NULL)  printf("errore 2\n");
    else {
        x = fgetc(fp);  //prendiamo il primo carattere del file (che in questo programma coincide con il valore iniziale di c)
        /*
        Il valore di ritorno della funzione fgetc è di tipo int e non di tipo char perché 
        ha un duplice significato: se coincide con la costante simbolica EOF, definita nel file di include stdio.h, significa che 
        il file pointer è posizionato a fine file e quindi nessun carattere è stato letto, mentre in caso contrario il valore di ritorno 
        rappresenta il carattere letto dal file. La costante simbolica EOF è definita in modo tale che non possa mai eguagliare 
        alcun carattere; solitamente vale −1. 
        */
        if (x != EOF) printf("x = %c\n", x);
        else printf("errore oppure fine file arrivata");

        //posizioniamo il puntatore a fine file per verificare
        fseek(fp, 0, 2);    //0 byte dalla fine del file
        if ((x = fgetc(fp)) != EOF)
            printf("questo non dovrebbe essere stampato");
        else printf("fine file arrivata (oppure errore)");   //viene stampato questo
        

        fclose(fp);
    }
    
}