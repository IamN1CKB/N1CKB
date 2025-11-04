#include <stdio.h>
/*
scrivere un programma che, dopo aver immesso un vettore di numeri interi vIn, scriva su un altro vettore vOut, tutti i numeri non nulli compresi tra 2 zeri
es vIn = {1,2,0,4,05,0} =>   vOut = {4,5}
*/
#define NMAX 100
int main() {
    int dimensione, vIn[NMAX], j = 0, vOut[NMAX/2];
    //per vOut dividiamo la dimensione per occupare meno spazio in memoria, dato che gli elementi di vOut non potranno mai essere maggiori della metà degli elementi di vIn
    printf("Dimensione dell'array (numero minore o uguale di %d): ", NMAX);
    scanf("%d", &dimensione);
    puts("Inserisci i valori dell'array");
    if (dimensione > 0 && dimensione<=NMAX) {
        //inizializzazione array
        for (int i = 0; i < dimensione; i++) {
            printf("vIn[%d] = ", i);
            scanf("%d", &vIn[i]);
        }

        //inizializzazione array 
        for (int i = 0; i < dimensione-2; i++)
        //dimensione -2 altrimenti controlla anche spazi di memoria non inizializzati, ossia v[dimensione + 2]
            if ((vIn[i] == 0) && (vIn[i+1] != 0) && (vIn[i+2] == 0))
                vOut[j++] = vIn[i+1];
                //nel caso di j viene prima riportato il valore e poi viene incrementato (se era ++j invece era il contrario)

        //stampa array vOut
        printf("vOut = [");
        for (int i = 0; i < j; i++)
            printf("%d ", vOut[i]);
        printf("\b]");  //\b è un carattere speciale che cancella il carattere precedente in console (uno spazio in questo caso)
    }
    else
        puts("Dimensione dell'array errata");
    
}