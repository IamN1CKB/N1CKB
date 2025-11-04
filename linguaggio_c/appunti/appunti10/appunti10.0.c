#include <stdio.h>
/*
Quando si vuole ripetere l’esecuzione di un gruppo di istruzioni, un’alternativa alle strutture iterative come for o 
while è rappresentata dalle funzioni ricorsive. Una funzione si dice ricorsiva se chiama se stessa direttamente o 
indirettamente. 
Per alcune classi di problemi le soluzioni ricorsive sono eleganti, sintetiche e più chiare delle altre. Un esempio di 
questo fatto si può trovare nel calcolo del fattoriale

Ricordiamo che il fattoriale n! del 
numero n, dove n è un intero maggiore o uguale a 2, è dato da:
n! = n⋅(n−1) ⋅ (n−2) ⋅(n−3) ⋅...⋅2⋅1
Inoltre 0! e 1! sono per definizione uguali a 1. 
Il fattoriale è ricorsivo per definizione. Può essere espresso come
n! = n⋅(n−1)!
ovvero il fattoriale di n è uguale a n moltiplicato per il fattoriale di n−1; ricorsivamente, 4! è dunque uguale a 4 
moltiplicato per il fattoriale di (4−1), e così via.
*/

long long fattoriale(long long n);

int main() {
    long long x;
    printf("scegli un numero di cui fare il fattoriale: ");
    scanf("%lld", &x);
    long long fat = fattoriale(x);
    if (fat == -1) printf("Numero negativo non calcolabile\n");
    else printf("%lld! = %lld\n", x, fat);
}

long long fattoriale(long long n) {
    if (n<0) return -1;
    else if (n == 1 || n == 0) return 1;
    else return (n * fattoriale(n-1));
}
/*
Per restituire il fattoriale al programma chiamante la funzione utilizzerà l’istruzione return:
return(n*fat(n-1));
che ritorna il valore di n moltiplicato per il fattoriale di n-1. Il calcolo del fattoriale di n-1 lo si ottiene invocando 
ancora una volta la stessa funzione fat e passandole come argomento n-1; in questo modo si ottiene l’iterazione. Il 
ciclo, a un certo punto, deve terminare, per cui è necessaria una condizione di fine con n = 0 o n = 1;

Confrontiamo la soluzione ricorsiva con la soluzione iterativa per calcolare il fattoriale:
a ogni chiamata di fattoriale viene creata una nuova variabile n locale a 
quell’ambiente. Quando termina il ciclo delle chiamate, ogni ambiente aperto si chiude e passa all’ambiente precedente 
il valore calcolato.




Introduciamo alcuni termini per definire varie ricorsioni:
    Ricorsione in coda: Un algoritmo ricorsivo si dice che e ricorsivo in coda se la chiamata ricorsiva e l'ultima istruzione 
        dell'algoritmo stesso. (caso del fattoriale che abbiamo fatto in questo file)

    Ricorsione Annidata: Un algoritmo si dice a ricorsione annidata se e composto da una funzione che ha come argomento una chiamata alla 
        funzione stessa

    -Ricorsione diretta: Questo è il tipo più comune di ricorsione, in cui una funzione chiama se stessa. Ad esempio, il calcolo del
        fattoriale di un numero è un tipico caso di ricorsione diretta.
    -Ricorsione indiretta o mutua: In questo caso, una funzione chiama un’altra funzione, che a sua volta chiama la prima funzione21.
        Questo crea una sorta di ciclo tra le due funzioni.



    -Ricorsione lineare: Si verifica quando c’è solo una chiamata ricorsiva all’interno della funzione. Un esempio di questo tipo di
        ricorsione è la successione di Fibonacci.
    -Ricorsione multipla: Si verifica quando una funzione fa più di una chiamata ricorsiva. Un esempio classico di ricorsione 
        non lineare è l’algoritmo per risolvere il problema delle torri di Hanoi.
        Un caso semplice e molto frequente di ricorsione multipla e quella detta binaria che si presenta quando sono presenti
        due sole chiamate ricorsive.
        (caso del programma prossimo: sequenza di Fibonacci)
*/