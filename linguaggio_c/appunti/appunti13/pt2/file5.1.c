#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 300
//adesso salviamo un vettore e una matrice in un file binario, poi nella prossima lezione li rileggeremo
//usiamo anche i sottoprogrammi, dove generiamo randomicamente la matrice e il vettore e poi li stampiamo
void creaMatVet(int mat[][N], int vet[], int l_vet, int l_mat, int h_mat);
void stampaMat(int mat[][N], int l, int h);
void stampaVet(int vet[], int l);

int salvaB(int vet[], int mat[][N], int l_vet, int l_mat, int h_mat, char *file);

int main(){
    int mat[N][N], vet[N], l_v, l_m, h_m;
    printf("decidi la lunghezza del vettore (<%d): ", N);
    scanf("%d", &l_v);
    printf("decidi la lunghezza della matrice (<%d): ", N);
    scanf("%d", &l_m);
    printf("decidi l'altezza della matrice (<%d): ", N);
    scanf("%d", &h_m);
    creaMatVet(mat, vet, l_v, l_m, h_m);
    stampaVet(vet, l_v);
    stampaMat(mat, l_m, h_m);

    //richiamiamo la funzione per il salvataggio su file binario
    if (salvaB(vet, mat, l_v, l_m, h_m, "array.bin") == -1) perror("ERR file");
}

void creaMatVet(int mat[][N], int vet[], int l_vet, int l_mat, int h_mat) {
    srand(time(NULL));
    for (int i = 0; i < l_vet; i++)
        vet[i] = rand()%100;
    for (int i = 0; i < h_mat; i++)
        for (int j = 0; j < l_mat; j++)
            mat[i][j] = rand()%100;
}
void stampaMat(int mat[][N], int l, int h) {
    printf("mat:\n");
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < l; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}
void stampaVet(int vet[], int l) {
    printf("vet:\n");
    for (int i = 0; i < l; i++)
        printf("%d ", vet[i]);
    printf("\n");
}

int salvaB(int vet[], int mat[][N], int l_vet, int l_mat, int h_mat, char *file) {
    FILE *fp = fopen(file, "wb");
    if (fp == NULL) return -1;
    else {
        //prima salviamo la lunghezza del vettore
        fwrite(&l_vet, sizeof(int), 1, fp);
        //dato che è solo una variabile dobbiamo salvare un elemento della grandezza di un int a partire dal puntatore di l_vet


        //salviamo poi il vettore
        //dobbiamo usare fwrite e salvare l_vet elementi di grandezza sizeof(int)
        fwrite(vet, sizeof(int), l_vet, fp);  //e questo era facile perché gia l'abbiamo fatto

        //salviamo adesso la lunghezza e l'altezza della matrice
        fwrite(&l_mat, sizeof(int), 1, fp);
        fwrite(&h_mat, sizeof(int), 1, fp);
        
        /*per salvare la matrice abbiamo 3 possibilità:
            1) salviamo tutta la matrice con la dimensione massima con anche gli elementi non inizializzati 
            fwrite(mat, size(int), N*N, fp)
            questo metodo non è per nulla ottimizzato perché salva molti valori inutili
            2) salviamo un elemento per volta tramite il doppio for che ti scorre tutta la matrice
            for (int i = 0; i < h_mat; i++)
                for (int j = 0; j < l_mat; j++)
                    fwrite(&mat[i][j], sizeof(int), 1, fp);
            questo metodo funziona ma non è ottimizzati siccome compie molti cicli
            3) salviamo la matrice riga per riga: è il metodo più ottimizzato e sarà quello che usiamo
        */
        for (int i = 0; i < h_mat; i++)
            for (int j = 0; j < l_mat; j++)
                fwrite(&mat[i][j], sizeof(int), 1, fp);
        //dobbiamo ricordarci l'ordine in cui abbiamo salvato il tutto perché poi ci servirà per leggerli in futuro
        fclose(fp);
        return 0;
    }
}
//vedi prossimo programma per la lettura da file binario della matrice e del vettore


//NOTA: SPESSO C'E UN PROBLEMA CON IL SALVATAGGIO DI MATRICI TROPPO GRANDI (GIà CON UN LATO DA 10 ELEMENTI)