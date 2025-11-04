#include <stdio.h>

/*
abbiamo operato una distinzione tra due tipi di parametri: i parametri formali e i parametri attuali. I 
parametri formali sono quelli dichiarati per tipo, numero e ordine nella definizione della funzione. I parametri attuali 
sono invece quelli che vengono passati alla funzione all’atto della chiamata.

nonostante bisogna passare i parametri concordando con il tipo, in certi casi abbiamo conversioni implicite come nel caso da float a double per cui non è necessaria una perfetta corrispondenza.

Occorre poi osservare che non è consentito il passaggio di parametri di tipo array, proprio perché in C il passaggio dei 
parametri avviene esclusivamente per valore. Infatti, se il compilatore si trovasse nella necessità di passare un array di 
tipo int a[1000], occorrerebbe una quantità di tempo proporzionale per effettuare il travaso di valori tra due array di 1000 int
*/
//Oltre al passaggio esplicito di parametri, è possibile anche il passaggio implicito. Infatti basta definire una variabile globale sia alla funzione chiamante sia a quella chiamata per ottenere la condivisione della variabile stessa. ad esempio:


char str[] = "Lupus in fabula";

int lung_string(void);

int main() {
    int l;
    l = lung_string();
    printf("La stringa %s ha %d caratteri\n", str, l);
    float numero_float = 3.14f;

}

int lung_string(void) {
    int i;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}