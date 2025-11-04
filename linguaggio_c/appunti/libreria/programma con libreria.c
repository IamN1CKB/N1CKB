#include <stdio.h>
#include "sommaf.h"

int main() {
    int a = 3;
    int b = 5;
    printf("%d + %d = %d\n", a, b, somma(a, b));
    printf("costante = %d", COSTANTE);
}

//per poter generare l'eseguibile dobbiamo dire a riga di comando varie informazione sulle librerie (non funziona opzione integrata di visual studio o codeblock)
//gcc -o 'programma con libreria.exe' 'programma con libreria.c' sommaf.o
//abbiamo dato l'informazione del nome dell'eseguibile, il file di input, e la libreria.o
//ora l'eseguibile può funzionare
//ciò che abbiamo fatto si chiama libreria statica e si 
