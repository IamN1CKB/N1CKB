#include <stdio.h>
/*
Scrivere una funzione ricorsiva che calcola il massimo comune divisore (MCD). 
Si ricorda al lettore che il MCD tra due numeri è l'intero più grande che li divide entrambi senza resto.
Teorema di Euclide:
“ogni divisore comune di a e b è divisore di a, b e del resto r della divisione tra a e b (a mod b), se questo non è nullo”
*/

int MCD(int, int);
int main(){
    int a, b;
    printf("decidi 2 numeri di cui fare l'MCD\n1) ");
    scanf("%d", &a);
    printf("2) ");
    scanf("%d", &b);
    printf("MCD(%d, %d) = %d\n", a, b, MCD(a, b));
}

int MCD(int a, int b) {
    if (a<b) return MCD(b, a);
    int r = a%b;
    if (r == 0) return b;
    return MCD(b, r);
}