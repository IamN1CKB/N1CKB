#include <stdio.h>
#define N_MAX 20 //il massimo numero di cifre per un numero intero codificato in 4 byte è 10
int main(){
    long x;  //numero in base b
    int b; //base del numero x
    int vet[N_MAX];
    int scelta;
    do {
        printf("scegli un numero x da convertire in decimale: ");
        scanf("%ld", &x);
        printf("scegli la base del numero (la base deve essere una cifra piu' grande di tutte le altre cifre di x): ");
        scanf(" %d", &b);
        //dobbiamo vedere quante cifre ha il numero x (il linguaggio c lo considera come un numero in base 10)
        //nel mentre possiamo salvare l'ultima cifra in un vettore, separando il numero cifra per cifra
        int cifre = 0, q = x;
        do {
            vet[cifre++] = q%10;    //prendi l'ultima cifra e la memorizzi nel vettore
            q = q/10;             //elimini l'ultima cifra del numero 
        } while (q!=0);

        //ora abbiamo il vettore ma con le cifre invertite (lavoreremo con questo)

        //adesso dobbiamo sommare tutte le cifre che sono moltiplicate per la base^ alla posizione della cifra
        //es  435 in base 6 = 4*6^2 + 3*6^1 + 5*6^0 in base 10 = 4*36 + 18 + 5 in base 10 = 167 in base 10 
        int numero_base_10 = 0;
        int base_cifra = 1;  //sarebbe la base elevata alla potenza della posizione della cifra, inizializzata a 1 perché sarebbe b^0 = 1
        for (int j = 0; j < cifre; j++) {
            numero_base_10 += vet[j]*base_cifra;
            base_cifra *= b;
        }
        printf("\n%ld in base %d = %d in base 10\n", x, b, numero_base_10);
        printf("inserisci 0 per terminare, un numero diverso da 0 per continuare: ");
        scanf("%d", &scelta);
    } while (scelta);
}