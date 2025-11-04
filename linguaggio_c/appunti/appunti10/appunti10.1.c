//sviluppiamo una funzione ricorsiva per calcolare la sequenza di Fibonacci di un numero
/*
La sequenza di Fibonacci è una sequenza numerica infinita di numeri naturali in cui i primi due termini sono 1 e 1, e ciascun altro
termine è uguale alla somma dei precedenti due. I termini della sequenza di Fibonacci sono detti numeri di Fibonacci e si indicano
con F(n), dove il pedice n specifica la posizione che ciascun numero ha all'interno della sequenza¹.

La sequenza di Fibonacci è definita ricorsivamente come segue:

F(n) = 0              se n = 0
F(n) = 1              se n = 1
F(n−1) + F(n−2)     se n ≥ 2

I primi quindici termini della sequenza di Fibonacci sono: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610.
*/
#include <stdio.h>
int Fibonacci(int);

int main() {
    int a, fib;
    printf("inserisci un numero (vedremo il corrispettivo numero nella sequenza di Fibonacci): ");
    scanf("%d", &a);
    fib = Fibonacci(a);
    if (fib == -1) printf("numero negativo non calcolabile\n");
    else printf("fib = %d", fib);
}

int Fibonacci(int x) {
    if (x<0) return -1;
    else if (x == 0 || x == 1) return x;
    else return (Fibonacci(x-1) + Fibonacci(x-2));
}

//questo codice non è molto ottimizzato siccome porta a calcolare gli stessi valori più di una volta in una stessa esecuzione