//Sviluppare una funzione che dato un intero stabilisce se questo è pari o dispari utilizzando un approccio ricorsivo.
#include <stdio.h>
int isPari(unsigned int n);
int isDispari(unsigned int n);

int main(){
    unsigned int x, scelta;
    printf("decidi un numero positivo: ");
    scanf("%d", &x);
    printf("scrivi: \n1 per vedere se è pari\n2 per vedere se è dispari\nscegli: ");
    scanf("%d", &scelta);
    switch (scelta) {
    case 1:
        if (isPari(x) == 1) printf("e' pari\n");
        else printf("non e' pari\n");
        break;
    case 2:
        if (isDispari(x) == 1) printf("e' dispari");
        else printf("non e' dispari\n");
        break;
    default:
        printf("errore scelta\n");
        break;
    }
}
/*
• Divide: Un numero è dispari se il decremento a uno del numero è pari e viceversa.
• Caso base: il numero 0 è pari per convenzione
• Impera: assumiamo per ipotesi induttiva che sappiamo verificare se un numero n è pari
• Combina: se chiedi se un numero è pari allora verifica che il decremento è dispari. Se chiedi se un numero è dispari verifica che NON sia pari.
*/

int isPari(unsigned int n) {
    if (n == 0) return 1;
    else return isDispari(n-1);
}
int isDispari(unsigned int n) {
    return !(isPari(n));
}