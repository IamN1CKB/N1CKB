#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*
Data una stringa (un vettore di char) stringa[First..Last] scrivere una funzione ricorsiva lineare che calcoli il numero di lettere maiuscole 
nella stringa. La funzione restituisce numero di lettere maiuscole
Si utilizzi la seguente funzione che ritorna il valore 
Vero, se il carattere fornito è maiuscolo:
isupper(char c);
Prototipo:
*/
int conta_maiuscole ( char str[], int First, int Last);
int main() {
    int i;
    char *str = malloc(sizeof(char));  //allochiamo dinamicamente solo per il primo carattere
    if (str == NULL) {
        perror("allocazione fallita");
        return -1;
    }
    
    printf("inserisci stringa: ");
    for (i = 0; (str[i] = getchar())!='\n'; i++) {
        str = realloc(str, (i+2)*sizeof(char));
        if (str == NULL) {
            perror("allocazione fallita");
            return -1;
        }
    }
    str[i] = '\0';
    printf("numero di maiuscole = %d\n", conta_maiuscole(str, 0, i-1));
}
/*
• Divide: la stringa di ingresso str[first..last] viene diviso nell'elemento di testa (str[first]), l'elemento a coda
    e la parte centrale della stringa (str[first+1..last-1]).
• Caso base: se la stringa ha un unico carattere la soluzione è banale, se il singolo carattere è maiuscolo si
    restituisce 1, altrimenti si restituisce 0. Allo stesso modo se la stringa e vuota la soluzione e altrettanto
    banale e pari a 0.
• Impera: si ritiene per ipotesi induttiva che si sappia risolvere correttamente il problema più semplice del calcolo
    delle occorrenze delle lettere maiuscole nella stringa str[first+1..last-1].
• Combina: si somma il numero di occorrenze della sotto-stringa str[first+1..last-1] con 1 se la prima lettera e l'ultima della
    stringa sono maiuscole, con 1 se solo uno delle 2 è maiuscola, con 0 se sono entrambe minuscole
*/
int conta_maiuscole (char str[], int First, int Last) {
    int cont;
    if (First==Last) {
        if (isupper(str[First])) return 1;
        return 0;
    }
    if (First>Last) return 0;
    cont = conta_maiuscole(str, First+1, Last-1);

    if (isupper(str[First]) || isupper(str[Last])) {
        if (isupper(str[First]) && isupper(str[Last])) return cont+2; 
        else return cont+1;
    }
    return cont;
}