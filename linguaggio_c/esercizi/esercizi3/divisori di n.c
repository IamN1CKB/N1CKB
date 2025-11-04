#include <stdio.h>
/*
scrivere un programma che verifica se un numero è primo
*/
int main(){
    int a, condizione = 0;
    printf("inserisci un numero: ");
    scanf("%d", &a);
    for (int i = 1; i <= a; i++)
        if (a%i == 0) condizione++;
    if (condizione == 2) printf("%d e' un numero primo", a);
    else printf("%d non e' un numero primo\n%d ha come %d divisori", a, a, condizione);
}