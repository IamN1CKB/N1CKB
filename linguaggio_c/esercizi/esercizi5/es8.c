#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 13 //dopo cambia a 100
/*
fai un programma di fusione ordinato
*/
int main(){
    srand(time(NULL));
    int vet1[N], vet2[N];
    int n = 10, m = 12;
    //printf("scegli un valore della lunghezza del primo vettore (<=%d)", N);
    //scanf("%d", &n);
    //printf("scegli un valore della lunghezza del secondo vettore (<=%d)", N);
    //scanf("%d", &m);

    //inizializzazione e stampa
    printf("vet1: ");
    for (int i = 0; i < n; i++){
        vet1[i] = rand()%100;
        printf("%d ", vet1[i]);
    }
    printf("\nvet2: ");
    for (int i = 0; i < m; i++){
        vet2[i] = rand()%100;
        printf("%d ", vet2[i]);
    }

    //ordiniamo i 2 vettori
    int condizione, temp, p, n1=n, m1=m;
    do {
        condizione = 0;
        for (int i = 0; i < n1-1; i++)
            if (vet1[i]>vet1[i+1]) {
                temp = vet1[i];
                vet1[i] = vet1[i+1];
                vet1[i+1] = temp;
                p=i+1;
                condizione = 1;
            }
        n1 = p;
    } while (condizione);


    do {
        condizione = 0;
        for (int i = 0; i < m1-1; i++)
            if (vet2[i]>vet2[i+1]) {
                temp = vet2[i];
                vet2[i] = vet2[i+1];
                vet2[i+1] = temp;
                p=i+1;
                condizione = 1;
            }
        m1 = p;
    } while (condizione);

    //stampa vettori ordinati
    printf("\n\n\nvet1 ordinato:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", vet1[i]);
    
    printf("\nvet2 ordinato:\n");
    for (int i = 0; i < m; i++)
        printf("%d ", vet2[i]);
    


    int vet3[2*N];      //vettore fusione
    int i=0;   //indice per vet1
    int j=0;   //indice per vet2
    int k=0;   //indice per vet3
    do {
        if (vet1[i]>=vet2[j])
            vet3[k++] = vet2[j++];
        else
            vet3[k++] = vet1[i++];
        
    } while (i<n && j<m);
    
    //adesso dobbiamo assegnare a vet3 i rimanenti valori
    do {
        if (i<n)
            vet3[k++] = vet1[i++];
        else
            vet3[k++] = vet2[j++];
    } while (i<n || j<m);
    
    
    printf("\n\nvet3:\n");
    for (int z = 0; z < k; z++)
        printf("%d ", vet3[z]);
    
        
    
    
    
    
    

}