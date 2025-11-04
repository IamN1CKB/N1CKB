#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*
Scrivere un programma che richieda all’utente i voti delle otto prove sostenute durante l’anno da diciotto
studenti di una classe e calcoli la media di ogni studente, la media di ogni prova e la media globale. Il programma dovrà
infine visualizzare l’intera matrice e la media globale.
[Suggerimento: si utilizzi una matrice di 19 linee e 9 colonne dove nelle prime otto vengono memorizzati in ciascuna linea
i voti di uno studente e nella nona la rispettiva media; nella diciannovesima linea viene invece memorizzata la media per prova.]
*/
#define PROVE 8
#define STUDENTI 18
int main() {
    float mat[STUDENTI + 1][PROVE + 1], somma_prove_1_studente, somma_voti_di_tutti_studenti; 
    //STUDENTI + 1 perché nell'ultima viene rappresentata la media della prova
    //PROVE + 1 perché nell'ultima viene rappresentata la media dello studente
    srand(time(NULL));
    for (int i = 0; i < STUDENTI; i++) {
        somma_prove_1_studente = 0;
        for (int j = 0; j < PROVE + 1; j++) {
            if (j != PROVE) {
                mat[i][j] = rand()%8 + 3;
                somma_prove_1_studente += mat[i][j];
            }
            else mat[i][j] = somma_prove_1_studente/PROVE;
        }
    }
    for (int i = 0; i < PROVE + 1; i++) {
        somma_voti_di_tutti_studenti = 0;
        for (int j = 0; j < STUDENTI; j++)
            somma_voti_di_tutti_studenti += mat[j][i];
        mat[STUDENTI][i] = somma_voti_di_tutti_studenti/STUDENTI; 
    }
    
    printf("\tstampa matrice\n");
    
    for (int i = -1; i < STUDENTI + 1; i++) {
        if (i == -1) {
            printf("prove: \t\t\t ");
            for (int j = 1; j <= PROVE; j++) {
                printf(" prova%d|", j);
            }
            printf("media studente");
        }
        else if (i!=STUDENTI) {
            printf("voti studente %d:    \t", i+1);
            for (int j = 0; j < PROVE + 1; j++) {
                if (j!=PROVE) printf("%.0f\t|", mat[i][j]);
                else printf("\t%.2f", mat[i][j]);
            }
        }
        else{
            printf("media delle prove:\t");
            for (int j = 0; j < PROVE + 1; j++)
                if (j!=PROVE) printf("%.2f\t|", mat[i][j]);
                else printf("\t%.2f", mat[i][j]);
        }
        printf("\n");
    }
    
    


            
}