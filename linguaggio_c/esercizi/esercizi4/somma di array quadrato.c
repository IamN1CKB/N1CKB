#include <stdio.h>
#include <math.h>
/*
scrivere un programma che, dopo avere immesso un vettore di interi v, verifichi che la somma dei numeri dell'array in valore assoluto sia un quadrato perfetto
*/
#define NMAX 100

int main() {
    int dimensione, v[NMAX], somma = 0;
    double radice;
    printf("Dimensione dell'array (numero minore o uguale di %d): ", NMAX);
    scanf("%d", &dimensione);
    puts("Inserisci i valori dell'array");
    if (dimensione > 0 && dimensione<=NMAX) {
        //inizializzazione array e somma degli elementi
        for (int i = 0; i < dimensione; i++) {
            printf("v[%d] = ", i);
            scanf("%d", &v[i]);
            somma += v[i];
        }
        somma = abs(somma);    //valore assoluto della somma
        printf("somma in valore assoluto: %d\n", somma);
        radice = sqrt(somma);   //radice del valore assoluto della somma (radic deve essere una variabile di tipo double)
        printf("radice della somma: %lf\n", radice);
        if (radice*radice == somma)
        //se il quadrato della radice coincide con il valore assoluto della somma allora è un quadrato perfetto
            printf("la somma è un quadrato perfetto");
        else
            printf("la somma non è un quadrato perfetto");
    }
    else
        printf("dimensione array errata");

}