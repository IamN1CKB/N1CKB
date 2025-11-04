#include <stdio.h>
int main()
{
    //calcolo del massimo comune divisore
    //i dati di ingresso sono interi: a, b
    //le precondizioni sui dati di input: a, b > 0
    //le post condizioni sui dati di output: se a, b = 0 => messaggio di errore.
    int a = 0;
    int b = 0;
    int mcd;
    int r;
    if (b>a) {
        int temp;
        temp = b;
        b = a;
        a = temp;
        printf("a = %d b = %d\n", a, b); //a = 66 e b = 24
    }
    while (b != 0) {
        r = a % b; //resto della divisione intera tra a e b
        a = b;
        b = r;   
    }
    mcd = a;
    printf("mcd = %d\n", mcd);   
}