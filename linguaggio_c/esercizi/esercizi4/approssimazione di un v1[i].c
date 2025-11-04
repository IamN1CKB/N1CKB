#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define N 50
/*
Scrivere un programma che, letti gli elementi di un vettore v1 e un numero k, determini l’elemento di v1 più
prossimo a k.
*/
int main() {
    int v1[N], k, distanza_da_k, j;
    srand(time(NULL));
    for (int i = 0; i < N; i++) v1[i] = rand()%100;
    for (int i = 0; i < N; i++) {
        printf("%d ", v1[i]);
    }
    printf("\nscegli un valore k: ");
    scanf("%d", &k);


    for (int i = 0; i < N; i++) {
        if (i==0) distanza_da_k = abs(k-v1[0]);
        if (abs(k-v1[i])<distanza_da_k) {
            distanza_da_k = abs(k-v1[i]);
            j=i;
        }
    }
        

    
    printf("il valore di v1 che si avvicina di più a k e' v1[%d] = %d", j, v1[j]);
    
    


    return 0;
}