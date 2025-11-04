#include <stdio.h>
#define righe_max 20
#define colonne_max 20
/*
crea una matrice in cui ogni elemento ci sono i numeri contati da 0 a (righe*colonne-1)
*/
int main(){
    int matrice[righe_max][colonne_max];
    int righe, colonne, cont = 0;
    printf("inserisci il numero di righe della matrice: ");
    scanf("%d", &righe);
    printf("inserisci il numero di colonne della matrice: ");
    scanf("%d", &colonne);
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            matrice[i][j] = cont;
            printf("%d\t", matrice[i][j]);
            cont++;
        }
        printf("\n");
    }
    
    

    int array[righe*colonne];
    cont = 0;  //ora usiamo cont come indice dell'array
    for (int riga = 0; riga < righe; riga++)
        for (int colonna = 0; colonna < colonne; colonna++)
            array[cont++] = matrice[riga][colonna];


    //visualizzazione array
    printf("vedi array\n");
    for (int i = 0; i < righe*colonne; i++) {
        printf("%d\t", array[i]);
    }
    
}