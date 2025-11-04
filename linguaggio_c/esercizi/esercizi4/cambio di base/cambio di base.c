#include <stdio.h>
#define StringaMassima 100
/*
convertiamo un numero in base 10 in binario
es: (11)_10 = 1011
*/
int main() {
    int x; //numero da convertire
    printf("scegli un numero in decimale da convertire (intero naturale): ");
    scanf("%d", &x);
    int v[32]; //gli interi in c sono codificati in 4 byte (ossia 32 bit)
    int q, r; //quoziente e resto
    int i = 0;  //variabile di conteggio
    printf("%d in decimale = ", x);
    do {
        q = x/2; //sarebbe il quoziente
        r = x%2;
        v[i++] = r;  //ci dobbiamo salvare i resti, siccome i resti formano il numero in binario
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
    printf(" in binario\n");
    //immaginiamo di voler stampare tutti i 32 bit del numero in binario
    //dobbiamo settare tutti i valori che stanno dopo v[i] nel vettore ancora non invertito a 0
    printf("scegli un altro numero da convertire in binario, ma stavolta rappresentando tutti i 32 bit: ");
    scanf("%d", &x); 
    printf("%d in decimale = ", x);
    //ora settiamo tutti gli elementi dell'array a 0
    i = 0;
    for (int j = 0; j < 32; j++) v[j] = 0;
    do {
        q = x/2; //sarebbe il quoziente
        r = x%2;
        v[i++] = r;  //ci dobbiamo salvare i resti, siccome i resti formano il numero in binario
        x = q;
    } while (x!=0);
    
    for (int j = 0; j < 32/2; j++) {
        temp = v[j];
        v[j] = v[32-1-j];
        v[32-1-j] = temp;
    }
    for (int j = 0; j < 32; j++) printf("%d", v[j]);
    printf(" in binario");

    
    
}