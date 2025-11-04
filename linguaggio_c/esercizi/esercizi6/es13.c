#include <stdio.h>
#define N 100
/*
Scrivere un programma che richieda all’utente una stringa e ne visualizzi una seconda, ottenuta dalla prima 
sostituendo tutte le lettere minuscole con delle maiuscole
*/
int main() {
    char str[N], a;
    printf("inserisci stringa: ");
    fgets(str, N, stdin);
    //dobbiamo settare l'ultimo carattere da \n a \0
    int len;
    while (str[len] != '\n') len++;
    str[len] = '\0';
    printf("la stringa e': %s\n", str);


    for (int i = 0; str[i]!='\0'; i++)
        if (str[i]>='a'&& str[i]<='z')
            str[i] += 'A'-'a';
    printf("la stringa e': %s", str);
    
   
    
}