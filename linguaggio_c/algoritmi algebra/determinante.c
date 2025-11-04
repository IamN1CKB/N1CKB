//determinante di una matrice quadrata inserita in un file di testo: vedi le regole del calcolo del determinante tramite il teorema di Laplace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int leggiMat(double*** mat);
void stampaMat(int n, double** mat);
double detMat(int n, double** mat);
void freeMat(int n, double*** mat);

int main(){
    double** mat;
    int n;    //ordine della matrice
    if((n=leggiMat(&mat))==-1){
        perror("errore");
        return -1;
    }
    else if (n==-2) {
        printf("Errore: Matrice non quadrata\n");
        return -1;
    }
    stampaMat(n, mat);

    printf("Il determinante della matrice e' %lf\n\n", detMat(n, mat));
    freeMat(n, &mat);
}


int leggiMat(double*** mat) {
    int n=0, cond=0;
    double a;      //variabile spazzatura (serve solo a leggere quanti elementi della matrice ci sono)
    FILE* fp= fopen("matrice.txt", "r");
    if(fp==NULL) return -1;
    //voglio leggere quanti elementi ci sono nella matrice, per calcolarne l'ordine (nella variabile n)
    do {
       n+=cond;
       cond=fscanf(fp, "%lf", &a);
       //la funzione fscanf restituisce il numero di dati salvati in variabili, se si arriva alla fine del file restituisce la costante EOF (-1) 
    } while (cond!=EOF && cond!=0);   //se arriviamo alla fine del file o non riusciamo più a leggere numeri
    if ((double)n != (sqrt(n)*sqrt(n))) return -2;    //caso in cui la matrice non è quadrata (n non è un quadrato perfetto)
    n = sqrt(n);

    (*mat) = (double **) calloc(n, sizeof(double*));     //allochiamo lo spazio per le righe
    if ((*mat) == NULL) {
        perror("spazio per le righe non allocato correttamente");
        return -1;
    }
    for (int i = 0; i < n; i++) {
        (*mat)[i] = (double*) calloc(n, sizeof(double));    //per ogni riga allochiamo lo spazio per le colonne
        if ((*mat)[i] == NULL) {
            perror("spazio per una riga non allocato correttamente");
            return -1;
        }
    }

    rewind(fp);     //posiziono di nuovo il puntatore al file ad inizio file per leggere le entrate della matrice
    for (int i = 0; i < n*n; i++)
        fscanf(fp,"%lf", &((*mat)[i/n][i%n]));
    fclose(fp);
    return n;
}

void stampaMat(int n, double** mat) {
    for (int i = 0; i < n; i++) {
        printf("|");
        for (int j = 0; j < n; j++)
            printf("%.2lf\t", mat[i][j]);
        printf("\b\b\b|\n");
    }
    printf("\n");
}


double detMat(int n, double** mat) {
    if (n==1) return mat[0][0];
    else {
        double** sottoMat = (double**) calloc(n-1, sizeof(double*));
        for (int i = 0; i < n-1; i++) sottoMat[i] = (double*) calloc(n-1, sizeof(double));
        double sum=0;

        int x;  //è una variabile che usiamo prima per scrivere la sotto-matrice, poi il fattore (-1)^i+j
        for (int z = 0; z < n; z++) {
            for (int i = 1; i < n; i++) {     //svolgo Laplace sempre sulla prima riga: la sotto-matrice non avrà mai la prima riga, quindi i parte da 1 e non da 0
                x=0;
                for (int j = 0; j < n-1; j++) {
                    if(j==z) x++;
                    sottoMat[i-1][j] = mat[i][j+x];
                }
            }
            //riutilizziamo x=(-1)^i+j    (i e j partono da 1 fino a n in algebra)
            //vediamo che
            //z=j-1 =>   j=z+1 (in programmazione C contiamo a partire da 0, in algebra da 1)
            //i=1 (facciamo Laplace sempre sulla prima riga)
            //quindi i+j = 1+z+1 = z+2   quindi (-1)^i+j=(-1)^z+2
            //se z+2 è pari (-1)^i+y = 1, altrimenti -1
            //se 2+z è pari, vuol dire che z è pari
            //quindi se z è pari dà x=1, altrimenti x=-1
            if (z%2==0) x=1;
            else x=-1;
            sum += (mat[0][z]) * (x) * detMat(n-1, sottoMat);
        }
        freeMat(n-1, &sottoMat);
        return sum;
    }
}

void freeMat(int n, double*** mat) {
    for (int i = 0; i < n; i++)
        free((*mat)[i]);
    free(*mat);
}