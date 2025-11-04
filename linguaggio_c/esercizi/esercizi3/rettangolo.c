#include <stdio.h>
/*
Predisporre un programma che stampi un rettangolo la cui cornice sia costituita da caratteri asterisco, e la parte 
interna da caratteri Q. Il numero di linee e di colonne del rettangolo viene deciso a tempo di esecuzione dall’utente; per 
esempio se il numero delle linee è uguale a 5 e il numero di colonne a 21, sul video deve apparire
*********************
*QQQQQQQQQQQQQQQQQQQ*
*QQQQQQQQQQQQQQQQQQQ*
*QQQQQQQQQQQQQQQQQQQ*
*********************
*/
int main(){
    int righe, colonne;
    char interno, esterno;
    puts("Formazione rettangolo");
    printf("Decidi il numero di righe (>2): ");
    scanf("%d", &righe);
    printf("Decidi il numero di colonne (>2): ");
    scanf("%d", &colonne);
    printf("Decidi carattere del perimetro: ");
    scanf(" %c", &esterno);
    printf("Decidi carattere del area: ");
    scanf(" %c", &interno);

    //stampa rettangolo
    for (int i = 0; i < colonne; i++)
        printf("%c ", esterno);
    printf("\n");
    
    for (int i = 0; i < righe; i++) {
        printf("%c ", esterno);    
        for (int j = 1; j < colonne-1; j++)
            printf("%c ", interno);
        printf("%c\n", esterno);
    }
    for (int i = 0; i < colonne; i++)
        printf("%c ", esterno);
    
}