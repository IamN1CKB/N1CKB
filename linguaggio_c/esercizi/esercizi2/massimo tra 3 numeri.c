#include <stdio.h>
/*stabiliamo qual è il massimo tra 3 numeri scelti dall'utente senza array o cicli*/
int main()
{
    int a, b, c, max;
    a = 11;
    b = 3;
    c = 2;
    printf("inserisci il valore della variabile a: ");
    scanf("%d", &a);
    printf("inserisci il valore della variabile b: ");
    scanf("%d", &b);
    printf("inserisci il valore della variabile c: ");
    scanf("%d", &c);

    if (b<=a) {
        if (b<a)
            if (c<=a) {        //c<=a && b<a
                max = a;
                if (c<a)        //c<a && b<a
                    printf("a = massimo\n");
                else            //b<a=c
                    printf("a e c sono uguali e sono entrambi dei massimi\n");
            }
        else {                  //a=b
            if (c<=a) {         //c<=a=b
                max = a;
                if (c<a)         //c<a=b
                    printf("a e b sono uguali e sono entrambi dei massimi\n");
                else             //c=a=b
                    printf("a, b e c sono uguali\n");
            }
            else {               //a=b>c
                printf("c = massimo\n");
                max = c;
            }
        }   
    }
    else  {                      //(b>a)
        if (c<=b) {             //c<=b && a<b
            max = b;
            if (b>c)
                printf("b = massimo\n");
            else
               printf("b e c hanno lo stesso valore e sono i massimi\n");
        }
        else {                  //a<b<c
            printf("c = massimo\n");
            max = c;
        }
    }
    printf("il massimo = %d\n", max);
}