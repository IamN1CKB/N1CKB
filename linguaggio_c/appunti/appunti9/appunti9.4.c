#include <stdio.h>
#define N 100
//usiamo una strategia simile con gli array
//calcoliamo la lunghezza di una stringa
int strLen(char* str);


void main() {
    printf("inserisci stringa: ");
    char str[N];
    fgets(str, N, stdin);
    printf("la lunghezza della stringa è %d\n", strLen(str));  //str è già l'indirizzo del primo carattere
    printf("ricontrolliamo se alle esecuzioni successive funziona lo stesso: len = %d", strLen(str));
}


int strLen(char* str) {
    int i = 0;
    while (*(str + i) != '\n' && *(str + i) != '\0') i++;
    if (*(str+i) == '\n') *(str+i) = '\0';   //non solo voglio ricavare la lunghezza ma anche sostituire l'ultimo \n con \0 nel caso ci sia (faccio 2 cose insieme)
    return i;
}

//dunque se si deve passare un array (che si debba modificare o meno) deve essere passato il puntatore, ma in realtà dato che è scomodo passare il puntatore sempre, in C scrivere l'array come tipo array[] in un parametro è gia un puntatore (vedi prossimo programma)
//se invece dobbiamo passare variabili semplici, allora dobbiamo controllare se quella variabile deve essere modificata o meno per essere passata come puntatore