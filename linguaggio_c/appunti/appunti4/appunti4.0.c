#include <stdio.h>
#define N 100
int main(){
    //da ora in poi gli appunti saranno fatti alla cazzo (meno dettagliati con i commenti) perché devo fare presto ad
    //arrivare in pari col prof

    //array è una sequenza di dati strutturati e tutti dello stesso tipo
    int array[6];   //puoi usare gli indici da 0 a 5
    array[0] = 32;
    array[4] = 40;
    array[5] = 2;
    printf("valore a caso: %d\n", array[1]); //non inizializzato
    printf("array[4] = %d\n", array[4]);  //inizializzato a 40
   

    //inizializzazione e dichiarazione vettore
    int a[5];
    printf("inizializzazione array di 5 elementi\n");
    for (int i = 0; i < 5; i++) {
        printf("inserisci elemento %d: ", i);
        scanf("%d", &a[i]);
    }
    //stampa vettore
    for (int i = 0; i < 5; i++)
        printf("elemento %d: %d\n", i, a[i]);
    
    printf("ricerca massimo e minimo dell'array\n");
    int max = a[0];
    int min = max;
    for (int i = 1; i < 5; i++) { //i inizia a 1 perché a[0] già è stato paragonato
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
    }
    printf("il massimo e' %d. il minimo e' %d\n", max, min);
    puts("somma e media degli elementi del vettore");
    float media, somma = 0;
    for (int i = 0; i < 5; i++)
        somma += a[i];
    media = somma/5;
    printf("la somma e' %.0f, e la media e' %f\n", somma, media);

    /*Per gli array l’inizializzazione è possibile solamente se sono stati dichiarati come extern o come static;
    quest’ultima classe di variabile verrà esaminata in seguito.
    Le variabili extern sono quelle che vengono definite prima di main. L’inizializzazione si ottiene inserendo i
    valori tra parentesi graffe, separati da una virgola:*/
    int voti[6] = {11, 18, 7, 15, 21, 9};
    /*Il compilatore fa la scansione dei valori presenti tra parentesi graffe da sinistra verso destra e genera altrettanti
    assegnamenti consecutivi agli elementi del vettore, rispettando la loro posizione; dunque voti[0] assume il valore 11,
    voti[1] 18, voti[2] 7 ecc. Quando tutti gli elementi dell’array vengono inizializzati è possibile omettere
    l’indicazione del numero di elementi, e scrivere*/
    int voti1[] = {11, 18, 7, 15, 21, 9};
    /*È infatti il compilatore stesso che conta i valori e di conseguenza determina la dimensione del vettore.
    Gli array di caratteri, comunemente detti stringhe, possono essere inizializzati anche inserendo il loro contenuto tra
    doppi apici:*/
    char frase[] = "Analisi, requisiti";
    


    printf("\n");
    //matrici
    int mat[4][3];
    //esistono anche matrici di più dimensioni
    int mat2[2][3][4]; // matrice di 2*3*4 elementi (24 elementi)

    //inizializzazione matrice bidimensionale mat
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++) {
            printf("mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    
    //stampa
    printf("stampa matrice\n");
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            printf("mat[%d][%d] = %d\n", i, j, mat[i][j]);

    //somma degli elementi della matrice
    somma = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            somma += mat[i][j];

    printf("somma = %.f\n", somma);   //somma era un float

    //possiamo scorrere gli elementi di una matrice anche in un altro modo (uno più compatto ma che non userò mai)
    somma = 0;
    for (int i = 0; i < 4*3; i++)
        somma += mat[i/3][i%3]; //i/3 ci dà la riga, i%3 ci dà la colonna
    
    printf("somma = %.f\n", somma);

    //da una matrice quadrata stampa la diagonale che parte dal basso a sinistra a arriva in alto a destra
    int l, mat3[N][N];
    printf("scegli lunghezza (= altezza) della matrice quadrata: ");
    scanf("%d", &l);
    for (int i = 0; i < l*l; i++) {
        printf("mat3[%d][%d]: ", i/l, i%l);
        scanf("%d", &mat3[i/l][i%l]);
    }
    printf("stampiamo tutta la matrice come un quadrato:\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++)
            printf("%d\t", mat3[i][j]);
        printf("\n");
    }
    
    printf("\nstampiamo la anti-diagonale: ");
    for (int i = 0; i < l; i++) {
        printf("%d ", mat3[l-i-1][i]);
    }

    //Inoltre possiamo dichiarare e inizializzare una matrice nel codice anche in questo modo
    int miaMatrice[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    printf("\nmiaMatrice:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%d ", miaMatrice[i][j]);
        printf("\n");
    }
    

    return 0;
} 