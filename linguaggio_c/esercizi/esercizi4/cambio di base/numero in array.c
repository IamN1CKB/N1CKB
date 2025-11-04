#include <stdio.h>
#define N_MAX 10
int main(){
    int numero; // Numero da separare in cifre
    scanf("%d", &numero);
    int cifre = 0;  //conta le cifre del numero
    int vet[N_MAX];    //vettore in cui memorizzare il numero cifra per cifra

    while (numero > 0) {
        vet[cifre] = numero % 10; // Ottieni l'ultima cifra e la memorizzi nel vettore
        numero /= 10; // Rimuovi l'ultima cifra, in modo che alla prossima iterazione ci sia una cifra in meno
        cifre++;
    }
    //ora abbiamo il vettore ma con le cifre invertite. es numero = 1256 =>  vet[] = {6 5 2 1}
    int temp; //variabile temporanea
    for (int i = 0; i < cifre/2; i++) {
        temp = vet[i];
        vet[i] = vet[cifre-1-i];
        vet[cifre-1-i] = temp;
    }
    

    for (int i = 0; i < cifre; i++)
        printf("%d ", vet[i]);
    
}