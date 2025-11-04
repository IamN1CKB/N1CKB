#include <stdio.h>
/*
 Scrivere un programma che, richiesto il numero MM rappresentante il valore numerico di un mese, visualizzi, se 1
≤ MM ≤ 12, il nome del mese per esteso, altrimenti la frase “Valore numerico non valido”.
*/
int main() {
    int MM;
    printf("Inserisci un numero di un mese: ");
    scanf("%d", &MM);
    switch (MM) {
    case 1:
        puts("il mese = gennaio");
        break;
    case 2:
        puts("il mese = febbraio");
        break;
    case 3:
        puts("il mese = marzo");
        break;
    case 4:
        puts("il mese = aprile");
        break;
    case 5:
        puts("il mese = maggio");
        break;
    case 6:
        puts("il mese = giugno");
        break;
    case 7:
        puts("il mese = luglio");
        break;
    case 8:
        puts("il mese = agosto");
        break;
    case 9:
        puts("il mese = settembre");
        break;
    case 10:
        puts("il mese = ottobre");
        break;
    case 11:
        puts("il mese = novembre");
        break;
    case 12:
        puts("il mese = dicembre");
        break;
    default:
        puts("Valore numero non valido");
        break;
    }
    
    
}