#include <stdio.h>
#define N 100
void main() {
    //proviamo a contare quanti caratteri ci sono nel file 'caratteri da contare'
    int n, n_caratteri = 0;
    char buf[N];
    FILE *fp;
    fp = fopen("caratteri da contare", "r");
    if (fp == NULL) printf("file \"caratteri da contare\" non aperto\n");
    else {
        printf("file \"caratteri da contare\" aperto\n");
        do {
            n = fread(buf, sizeof(char), N, fp);
            //siccome non vogliamo salvare i caratteri in nessun vettore, usiamo ciclicamente lo stesso vettore buf, che userà sempre le stesse aree di memoria, sostituendole ogni volta con i valori nuovi
            n_caratteri += n;
        } while (n>0);
        
        printf("i caratteri nel file sono %d\n", n_caratteri);
        fclose(fp);
    }
    
    //prossima lezione continuo
}