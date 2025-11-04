#include <stdio.h>
/*
convertiamo un numero in base 10 in binario
es: (11)_10 = 1011
*/
int main() {
    int x; //numero da convertire
    int b; //base della conversione
    int scelta;
    do {
        printf("scegli un numero in decimale da convertire (intero naturale): ");
        scanf("%d", &x);
        printf("scegli in che base convertirlo (base<10): ");
        scanf("%d", &b);
        int v[32]; //gli interi in c sono codificati in 4 byte (ossia 32 bit) in binario
        int q, r; //quoziente e resto
        int i = 0;  //variabile di conteggio
        printf("%d in decimale = ", x);
        do {
            q = x/b; //sarebbe il quoziente
            r = x%b;
            v[i++] = r;  //ci dobbiamo salvare i resti, siccome i resti formano il numero nella base b
            x = q;
        } while (x!=0);
        //dobbiamo invertire l'array
        int temp;
        for (int j = 0; j < i/2; j++) {
            temp = v[j];
            v[j] = v[i-1-j];
            v[i-1-j] = temp;
        }

        for (int j = 0; j < i; j++) printf("%d", v[j]);
        printf(" in base %d\n", b);
        printf("inserisci 0 per terminare, un numero diverso da 0 per continuare: ");
        scanf("%d", &scelta);
    } while (scelta);
    
}