#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
/*
Modificare l’algoritmo di ricerca binaria nel caso il vettore sia ordinato in modo decrescente invece che crescente
*/
int main(){
    int vet[N];
    int n, l;
    l = 10;
    printf("inserisci lunghezza del vettore (<%d): ", N);
    scanf("%d", &l);
    n=l;
    srand(time(NULL));

    //inizializziamo il vettore e stampiamolo
    for (int i = 0; i < n; i++)
        vet[i] = rand()%100;
    int condizione, temp, p;
    do {
        condizione = 0;
        for (int i = 0; i < n-1; i++) {
            if (vet[i]<vet[i+1]) {
                temp = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = temp;
                condizione = 1;
                p=i+1;
            }
        }
        n=p;
    } while (condizione);

    //stampa vettore
    printf("vet: ");
    for (int i = 0; i < l; i++)
        printf("%d ", vet[i]);

    //applichiamo la ricerca binaria per vettore ordinato decrescente
    int a = 0, b = l-1;   //estremi dell'intervallo in cui cercare
    int m;   //punto medio
    int x;
    printf("\ninserisci numero da cercare: ");
    scanf("%d", &x);
    condizione = 1;
    do {
        m  = (a + b)/2;
        if (x==vet[m]) condizione = 0; 
        else
            if (x<vet[m])
                a=m+1;
            else
                b=m-1;
    } while (a<=b && condizione);

    if (!condizione)
        printf("elemento %d trovato all'indice %d", x, m);
    else
        printf("elemento non trovato");
    

    
    
        
}