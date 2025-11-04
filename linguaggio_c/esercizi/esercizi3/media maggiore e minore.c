#include <stdio.h>
/*
Predisporre un programma, che determini il maggiore, il minore e la media degli n valori immessi dall’utente
*/
int main(){
    int x, n, min, max;
    float media, somma = 0;
    do {
        printf("Decidi quanti numeri vuoi inserire (scrivi un numero > 0, 0 per terminare): ");
        scanf("%d", &x);
    } while (x<0);
    if (x != 0) {
        for (int i = 1; i <= x; i++) {
            printf("inserisci il %d numero: ", i);
            scanf("%d", &n);
            somma += n;
            if (i==1) min = max = n;
            if(n<min) min = n;
            else if(n>max) max = n;
        }
        media = somma/x;
        printf("la media e' %f\n", media);
        printf("il minimo e' %d\n", min);
        printf("il massimo e' %d\n", max);
    }
    
    
}