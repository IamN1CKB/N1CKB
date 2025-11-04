#include <stdio.h>
#include <math.h>
#define ROW_MAX 100
#define COL_MAX 145
#define PI 3.14
/*
stampare in console il grafico della funzione coseno con *
*/
int main() {
    //stampiamo da 0 a 2pi-greco
    //dobbiamo decidere in quante righe e colonne stampare questo grafico in modo che possiamo rappresentarlo in console
    double x = 0;     //varia da 0 a 2*PI
    double y = cos(x);   //1 in questo caso ma varia da -1 a 1
    //siccome non possiamo stampare alla riga -1, rappresentiamo una traslazione di questa funzione, ossia cos(x) + 1, in cui y varia da 0 a 2
    //rappresentando con le colonne su console, y deve variare da 0 a COL_MAX
    
    for (int i = 0; i < ROW_MAX; i++) {
        x = (i*2*PI)/ROW_MAX;    //deve restituire un valore da 0 a 2pi per questa proporzione
        //x : 2pi = i : ROW_MAX   =>  2*pi*i/ROW_MAX
        y = cos(x) + 1;     //restituisce un valore tra 0 e 2
        for (int j = 0; j < COL_MAX; j++) {
            //temp = (y*COL_MAX)/2;   //questo dalla proporzione
            //temp : COL_MAX = y : 2 =>  temp = (y*COL_MAX)/2
            
            if ((((y*COL_MAX)/2)>j) && (((y*COL_MAX)/2)<j+1)) printf("*");  //se si trova tra 2 valori di j stampa *
            else printf(" ");
        }
        printf("\n");
    }
    
}