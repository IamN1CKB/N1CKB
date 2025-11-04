#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 100
/*
scrivi un programma di ricerca binaria e mostra in console ogni passo
*/
int main() {
    srand(time(NULL));
    int vet[N];
    int n = 10;
    printf("inserisci la lunghezza del vettore (<=100): ");
    scanf("%d", &n);

    //inizializzazione e stampa vettore
    for (int i = 0; i < n; i++) vet[i] = rand()%100;

    //ci serve un vettore ordinato
    int n1 = n;
    int condizione;
    int p;     //punto da cui non controllare più
    int temp;
    do {
        condizione = 0;
        for (int i = 0; i < n1; i++)
            if (vet[i]>vet[i+1]) {
                temp = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = temp;
                condizione = 1;
                p= i+1;
            }
        n1=p;
    } while (condizione);

    printf("vet: ");
    for (int i = 0; i < n; i++)
        printf("%d ", vet[i]);
    
    

    //ricorda la ricerca binaria, ossia cambiamo l'intervallo in cui cerchiamo ogni volta
    //dobbiamo fissare gli estremi
    int x; //elemento da cercare
    printf("\ninserisci elemento da cercare: ");
    scanf("%d", &x);
    int a=0, b=n-1;
    int m;   //punto medio
    int pos=-1;
    do {
        m = (a+b)/2;
        if (vet[m] < x)
            a=m+1;
        else if(vet[m] > x)
            b=m-1;
        else
            pos = m;
        
        printf("m = %d\ta = %d\tb= %d\n", m, a, b);
    } while (a<=b && pos==-1);
    
    
    if (pos == -1)
        printf("elemento non trovato");
    else
        printf("elemento trovato all'indice %d", pos);
    
    
    

    
}