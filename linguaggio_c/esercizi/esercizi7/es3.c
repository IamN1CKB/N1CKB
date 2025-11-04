#include <stdio.h>
#define N 100
/*
Scrivere una funzione che, data una stringa di caratteri, converta tutte le lettere minuscole in maiuscole. Si passi la 
stringa tramite variabile globale.
*/
char str[N];
void conversione();

void main() {
    printf("inserisci una stringa (< di %d caratteri): ", N);
    fgets(str, N, stdin);
    conversione();
    printf("stringa aggiornata: %s", str);
}


void conversione() {
    int i;
    for (i = 0; str[i] != '\n'; i++)
        if ((str[i] >= 'a') && (str[i]<='z'))
            str[i] += 'A' - 'a';


    str[i] = '\0';  //nel dubbio sistemiamo anche lo \n finale
    
}