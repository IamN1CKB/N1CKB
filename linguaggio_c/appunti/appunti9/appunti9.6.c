#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
//passare una matrice in un parametro nella definizione di una funzione è leggermente diverso dall'array
//facciamo un esempio di un sottoprogramma che ti genera una matrice di interi con dimensioni scelte dall'utente ed elementi generati casualmente
void randMat(int mat[][N], int *l, int *h);
/*nel caso della matrice possiamo passare (con N  che è la dimensione massima):
    - "int mat[N][N]"
    - "int mat[][N]"
In C non è possibile specificare solo la dimensione della prima dimensione e lasciare la seconda dimensione aperta come int matrice[N][]. La ragione di ciò è che il compilatore ha bisogno di sapere la dimensione di tutte le dimensioni eccetto l'ultima quando si tratta di array multidimensionali.

Quando si dichiara un array multidimensionale come parametro di una funzione, è necessario specificare almeno la dimensione della seconda dimensione. Quindi, puoi dichiarare il parametro come int matrice[N][N] come mostrato negli esempi precedenti, oppure come int matrice[][N], dove la prima dimensione (righe) può variare, ma la seconda dimensione (colonne) è fissata a N. questo perché una matrice è salvata in memoria riga per riga con la dimensione massima delle colonne. Quindi per poter operare con il puntatore al primo elemento di un array multidimensionale, dobbiamo sapere la grandezza di tutte le dimensioni, eccetto la prima

*/
void stampaMat(int mat[][N], int l, int h);
void main(){
    int mat[N][N];
    int l, h;


}
void randMat(int mat[][N], int *l, int *h) {
    srand(time(NULL));
    printf("scegli la lunghezza della matrice (<%d): ", N);
    scanf("%d", l);  //l è già un puntatore (non abbiamo bisogno di &l, che è un puntatore di puntatore)
    printf("scegli l'altezza della matrice (<%d): ", N);
    scanf("%d", h);
    for (int i = 0; i < h; i++)
        for (int j = 0; j < l; j++)
            mat[i][j] = rand()%100;
}
void stampaMat(int mat[][N], int l, int h) {
    printf("mat:\n");
    for (int i = 0; i < h; i++){
        for (int j = 0; j < l; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
    printf("\n");
}