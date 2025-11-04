#include <stdio.h>
#define N 100
/*
problema del pane celtico (simile ma non uguale alla congettura di collatz)
dati a, b come numeri interi naturali, se sono entrambi pari:
a = a/2
b = b/2
se sono entrambi dispari:
a = 2a +1
b = 2b +1
se solo a è dispari:
a = a+3
se solo b è dispari:
b = b+3

tutto questo deve concludersi quando a = b = 1
le domande sono? quante interazioni ci vogliono per valori di a e b che vanno da 0 a 1000?
succede sempre che per ogni numero di a e b in questo intervallo si arriva alla coppia a = 1 e b = 1 
*/
int main() {
    int a, b, cont = 0;
    printf("inserisci a: ");
    scanf("%d", &a);
    printf("inserisci b: ");
    scanf("%d", &b);

    while (!((a == 1) && (b == 1)) && cont<N) { //limito le iterazioni a N
        if (a%2 == 0) {
            if (b%2 == 0) {   //a e b sono pari
                a /= 2;
                b /= 2;
            }
            else//a è pari e b è dispari
                b += 3;
        }
        else {
            if (b%2 == 0)   //a è dispari e b è pari
                a += 3;
            else {   //a e b sono dispari
                //a = a + 2a + 1 = 3a + 1
                a = 3*a + 1;    //stessa cosa per b
                b = 3*b + 1;
            }
        }
        cont++;
        printf("a = %d\nb = %d\n\n", a, b);
    }
    if ((a!=1) || (b!=1))
        printf("l'algoritmo non converge ma resta bloccato in un ciclo infinito\n");
        //alcuni numeri in cui l'algoritmo non converge sono le coppie (1,2) (7,1) (635,134) ma non siamo riusciti a trovare un modo per capire con che criterio esistono queste coppie di numeri (nessuno al mondo ci è riuscito)
    else
        printf("sono state fatte %d iterazioni", cont);
    
}