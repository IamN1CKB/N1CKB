#include <stdio.h>
#define N 100


void main() {
    /*
    Il C mette a disposizione una funzione per conoscere la posizione corrente del file pointer; tale funzione prende il nome di ftell e si usa nel seguente modo:
    */
    FILE *fp;
    long n;
    fp = fopen("file", "r");
    if (fp == NULL) printf("errore file");
    else {
        n = ftell(fp);
        /*
        La funzione ftell ritorna il valore di quanti byte dista la posizione corrente del file pointer dall'inizio del file; se si verifica un errore, per esempio se il file non è stato aperto, ftell ritorna un valore negativo. S
        */
        printf("puntatore inizio file (byte di distanza dall'inizio file) = %ld\n", n);  //inizialmente dato che non è stata fatta nessuna operazioni il puntatore al file sta al primo elemento, e dista di 0 byte dall'inizio, per questo ftell riporta 0

        //portiamo il puntatore alla fine del file
        fseek(fp, 0, 2);   //2 fa partire dall'ultima posizione e lo sposto di 0 byte
        n = ftell(fp);
        printf("puntatore fine file (byte di distanza dall'inizio file) = %ld\n", n);
        //in questo modo abbiamo calcolato la dimensione del file in numero di byte
    }
}