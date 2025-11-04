#include <stdio.h>
#include <stdlib.h>

typedef struct soluzioniInfinite {
    char* varLibere;
    double* terminiNoti;
} SolInf;

//algoritmo di Gauss-Jordan
int leggiMat(double*** mat, int *l, int *h);
void stampaMat(double** mat, int l, int h);
void riduzioneGradini(double** mat, int l, int h);
int scambiaRiga(double** mat, int l, int h, int r1, int r2);
int isSistemaCompatibile(double** mat, int l, int* h);
void cancellaRiga(double** mat, int l, int* h, int riga);
void unicaSoluzione(double** mat, int l, int h, double* vet);
//void soluzioniINF(SolInf* vetSol, double** mat, int l, int h, int nSol);
void freeMat(double*** mat, int h);

int main() {
    double **mat;    //matrice completa del sistema
    int l;   //numero di incognite +1 (colonna dei termini noti)
    int h;   //numero di equazioni del sistema
    int hf;  //numero di equazioni finali del sistema
    int n;  //ordine delle soluzioni del sistema
    double* vetSol;  //vettore delle soluzioni (nel caso di un unica soluzione)
    SolInf VetSolInf;

    if (leggiMat(&mat, &l, &h)==-1){
        perror("errore file");
        return -1;
    }
    hf=h;
    stampaMat(mat, l, hf);
    riduzioneGradini(mat, l, hf);
    n=isSistemaCompatibile(mat, l, &hf);
    
    if (n==-1) printf("sistema incompatibile");
    else if (n==0){
        printf("Rango = n incognite => c'è un unica soluzione:\n");
        vetSol = (double*) calloc(l-1, sizeof(double));
        unicaSoluzione(mat, l, hf, vetSol);
        free(vetSol);
    }
    else {
        printf("ci sono inf^%d soluzioni", n);
        //soluzioniINF(&VetSolInf, mat, l, hf, n);
    }

    freeMat(&mat, h);
}


// void soluzioniINF(SolInf* vetSol, double** mat, int l, int h, int nSol) {
//     vetSol->varLibere = (char*) calloc(l-1, sizeof(char));
//     vetSol->terminiNoti = (double*) calloc(l-1, sizeof(int));
//     for (int i = 0; i < nSol; i++)
//     {
//         vetSol->varLibere[l-1-i] = 'A' +l-1-i;
//     }
// }

void unicaSoluzione(double** mat, int l, int h, double* vet) {
    for (int i = h-1; i>=0; i--) {
        for (int j = i; j < l-2; j++){
            vet[i] += -mat[i][j+1]*vet[j+1];
        }
        vet[i] += mat[i][l-1];
        vet[i] = vet[i]/mat[i][i];
        printf("%c =\t%.2lf\n", 'A'+i, vet[i]);
    }
}

void cancellaRiga(double** mat, int l, int* h, int riga){
    for (int i = riga; i < (*h)-1; i++){
        for (int j = 0; j < l; j++){
            mat[i][j]=mat[i+1][j];
        }
    }
    (*h)--;
    printf("cancelliamo l'equazione vuota E%d\n", riga+1);
    stampaMat(mat, l, *h);
}

int isSistemaCompatibile(double** mat, int l, int* h){
    double vet[100];
    int rigaNulla=0;  //variabile che è -1 se la riga è nulla, il valore di j in cui la riga non è più nulla, se la riga non è nulla
    for (int i = (*h)-1; i >= 0; i--) {
        for (int j = 0; j < l; j++) {
            if (mat[i][j]==0) rigaNulla = -1;
            else {
                rigaNulla = j;
                break;
            }
        }
        if (rigaNulla==-1) cancellaRiga(mat, l, h, i);  //cancelliamo la riga nulla
        else if (rigaNulla==l-1) return -1; //sistema incompatibile perché c'è l'eq   0=b   con b!=0
    }
    //vediamo quante soluzioni ci sono inf^(n-p)  con n=l-1 e p rango della matrice, ossia (*h) 
    return l-1-(*h);
}

void riduzioneGradini(double** mat, int l, int h) {
    double x = 1;
    int y=0;
    for (int z = 0; z < h; z++) {
        if(z>l) break;
        x=1;
        while (mat[z][z+y]==0 && z+x<h) {
            //questo ciclo si innesta se non troviamo l'equazione con il pivot!=0: scambia le righe fino quando non trova
            //una con il pivot giusto, o fino a finirle
            scambiaRiga(mat, l, h, z, z+x);
            x++;
            stampaMat(mat, l, h);
        }
        if (z+x==h) y++;    //nel caso di tutta la colonna nulla, spostiamo la riduzione y colonne dopo 
        for (int i = z+1; i < h; i++) {
            if(mat[z][z+y]!=0) {    //se è già uguale a zero passa alla prossima iterazione
                x=mat[i][z+y];

                for (int j = z+y; j < l; j++)
                    mat[i][j] = x*mat[z][j]-mat[z][z+y]*mat[i][j];   //applichiamo la riduzione a gradini
                printf("scambiamo l'equazione E%d con %.1lfE%d-(%.1lfE%d)\n", i+1, x, z+1, mat[z][z+y], i+1);
                stampaMat(mat, l, h);
            }
        }
    }
}

int scambiaRiga(double** mat, int l, int h, int r1, int r2) {
    double temp;
    for (int i = 0; i < l; i++) {
        temp = mat[r1][i];
        mat[r1][i]=mat[r2][i];
        mat[r2][i]=temp;
    }
    printf("scambiamo l'equazione %d con l'equazione %d\n", r1+1, r2+1);
}


int leggiMat(double*** mat, int* l, int* h) {
    FILE* fp=fopen("sistema.txt", "r");
    if (fp==NULL) return -1;

    if(fscanf(fp, "%d", h) == EOF || fscanf(fp, "%d", l)==EOF) return -1;


    *mat=(double**) calloc(*h, sizeof(double*));
    for (int i = 0; i < *h; i++) {
        (*mat)[i] = (double*) calloc(*l, sizeof(double));
    }

    for (int i = 0; i < (*h)*(*l); i++)
        fscanf(fp, "%lf", &((*mat)[i/(*l)][i%(*l)]));   
}


void stampaMat(double** mat, int l, int h) {
    char sign;
    for (int i = 0; i < h; i++) {
        printf(" ");
        if (i==0) printf(" /");
        else if(i==(h-1)) printf(" \\");
        else printf("| ");
        for (int j = 0; j < l; j++) {
            if (mat[i][j]>=0) sign = '+';


            if(j!=0 && j!=l-1 && mat[i][j]>=0) printf("%c", sign);
            printf("%.0lf", mat[i][j]);
            if (j<l-1) printf("%c", 'A'+j);
            if (j==l-2) printf("=");
            printf("\t");    
        };
        if (i==0) printf("\\");
        else if(i==(h-1)) printf("/");
        else printf(" |");
        printf("\n");
    }    
    printf("\n");
}

void freeMat(double*** mat, int h) {
    for (int i = 0; i < h; i++) free((*mat)[i]);
    free(*mat);
}
