#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//allochiamo dinamicamente una matrice e la inizializziamo randomicamente
void inizializzazione_random(int righe, int colonne, int **mat);
void stampaMat(int righe, int colonne, int **mat);

int main() {
    //la matrice va vista come un array di array con la stessa lunghezza
    int col, righe;   //le colonne e le righe le allochiamo staticamente
    printf("decidi numero di colonne: ");
    scanf("%d", &col);
    printf("decidi numero di righe: ");
    scanf("%d", &righe);
    /*
    ora dobbiamo quindi creare un array di righe, che sarebbe un array di puntatori, che possiamo definire come
    un puntatore di un puntatori
    */
    int **mat = (int **) calloc(righe, sizeof(int*));     //allochiamo lo spazio per le righe
    if (mat == NULL) {
        perror("spazio per le righe non allocato correttamente");
        return -1;
    }
    //dopo aver definito il primo array della matrice (ossia l'array delle righe), per ogni riga dobbiamo definire l'array del numero di colonne
    for (int i = 0; i < righe; i++) {
        mat[i] = (int*) calloc(col, sizeof(int));    //per ogni riga allochiamo lo spazio per le colonne
        if (mat[i] == NULL) {
            perror("spazio per la riga non allocato correttamente");
            return -1;
        }
    }


    inizializzazione_random(righe, col, mat);
    stampaMat(righe, col, mat);
    


    for (int i = 0; i < righe; i++)
        free(mat[i]);
    free(mat);
    //vedremo in futuro di allocare dinamicamente anche altre variabili strutturate (come le struct)
}

void inizializzazione_random(int righe, int colonne, int **mat) {
    srand(time(NULL));
    for (int i = 0; i < righe; i++)
        for (int j = 0; j < colonne; j++)
            mat[i][j] = rand()%100;
}

void stampaMat(int righe, int colonne, int **mat) {
    printf("mar:\n");
    for (int i = 0; i < righe; i++){
        for (int j = 0; j < colonne; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}
