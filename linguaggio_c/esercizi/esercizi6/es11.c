#include <stdio.h>
#define N 100
/*
Scrivere un programma che, letta una stringa composta da sole cifre (0..9), visualizzi accanto a ogni cifra il numero 
di volte che questa compare nella stringa. (Attenzione: si scriva un programma che utilizzi un solo ciclo.
*/
int main() {
    char str[N], a;
    printf("inserisci stringa con sole cifre (nemmeno spazi): ");
    int i;
    for (i = 0; ((str[i]=getchar())!='\n') && (str[i]>='0'&& str[i]<='9'); i++);
    str[i]='\0';
    printf("la stringa con solo cifre è: %s\n", str);

    int n[10], x;
    for (i = 0; i < 10; i++) n[i] = 0;
    
    for (i = 0; str[i]!='\0'; i++)
       // x = str[i] - '0';  //così trasformo i numeri da char a int
        n[str[i] - '0']++;
    
    //stampa
    for (i = 0; i < 10; i++)
        printf("%d => %d volte\n", i, n[i]);
    
}