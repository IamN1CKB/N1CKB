/*
Abbiamo osservato nel precedente capitolo che in C non è possibile passare un array a una funzione. Eppure esistono 
molti casi in cui è necessario non solo passare un array ma anche restituire una struttura dati più complessa della 
semplice variabile char o int.

possiamo risolvere questo problema passando i puntatori alle variabili (che siano array o meno)
Inoltre le variabili che noi costituiamo dentro una funzione vengono cancellate una volta conclusa la funzione, quindi non è possibile cambiare il valore di una variabile nel main. facciamo un esempio di scambio di variabili
*/
#include <stdio.h>
void scambiaErr(int a, int b);
void scambiaBuon(int* a, int* b);

void main() {
    int a = 2;
    int b = 6;
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    scambiaErr(a, b);  //scambiamo le due variabili senza puntatori


    printf("a = %d\n", a);  //non è cambiato un cazzo
    printf("b = %d\n", b);

    scambiaBuon(&a, &b);

    printf("\n\n\n\nscambio buono:\n");
    printf("a = %d\n", a);   //va buon
    printf("b = %d\n", b);
}
void scambiaErr(int a, int b) {
    int temp = a;
    a = b;
    b = temp; //non cambia nulla alle variabili nel main
}


void scambiaBuon(int* a, int* b) {  //in questo modo riceviamo gli indirizzi delle variabili rendendolo accessibili anche in questa funzione
    int temp = *a;   //lavoriamo con i valori degli indirizzi
    *a = *b;
    *b = temp;
}

