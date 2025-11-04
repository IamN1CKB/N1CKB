#include <stdio.h>
//prendiamo un vettore di float da un file di testo
//ordinamento array
//salvataggio in un file binario
//lettura array dal file binario
//stampa array a video
//ricerca elemento del vettore

void letturaV(float vet[], int *l);
void stampaV(float vet[], int l);
void ordinaV(float vet[], int l);
void salvaB(float vet[], int l);   //salva in file binario
void leggiB(float vet[], int l);   //ricava dal file binario
int ricerca(float vet[], int l, float ele); 
#define N 100

void main() {
    float vet[N];
    int l;
    letturaV(vet, &l);
    stampaV(vet, l);  //stampa non ordinata
    ordinaV(vet, l);
    stampaV(vet, l);  //stampa ordinata

    salvaB(vet, l);
    //per controllare che sia giusto il salvataggio leggiamo il vettore e stampiamolo
    leggiB(vet, l);

    stampaV(vet, l);  //stampa vettore da file
    
    //ricerca elemento del vettore
    float x;
    printf("elemento da ricercare?: ");
    scanf("%f", &x);
    int m = ricerca(vet, l, x);
    if (m!=-1)
        printf("l'elemento %f si trova all'indice %d\n", x, m);
    else
        printf("l'elemento %f non e' stato trovato\n", x);
    

}


void letturaV(float vet[], int *l) {
    //leggiamo il vettore da un file di testo in cui il primo numero è la grandezza del vettore, e gli altri numeri sono gli elementi del vettore
    FILE *fp = fopen("file1/fin.txt", "r");
    if (fp == NULL) printf("ERR fin.txt\n");
    else {
        fscanf(fp,"%d ", l);
        for (int i = 0; i < *l; i++)
            fscanf(fp, "%f ", &vet[i]);
        fclose(fp);
    }
    
}

void stampaV(float vet[], int l) {
    printf("vet: ");
    for (int i = 0; i < l; i++)
        printf("%.2f\t", vet[i]);
    printf("\n");
}

void ordinaV(float vet[], int l) {
    int condizione, p;
    float temp;
    do {
      condizione = 0;
        for (int i = 0; i < l-1; i++) {
            if (vet[i]>vet[i+1]) {
                temp = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = temp;
                condizione = 1;
                p = i + 1;
            }
        }
        l = p;
    } while (condizione);
}

void salvaB(float vet[], int l) {   //salva in file binario
    FILE *fp = fopen("file1/file.bin", "w");
    if (fp == NULL) printf("ERR file.bin\n");
    else {
        fwrite(&l, sizeof(int), 1, fp);
        fwrite(vet, sizeof(float), l, fp);
        fclose(fp);
    }
    
}

void leggiB(float vet[], int l) {
    FILE *fp = fopen("file1/file.bin", "r");
    if (fp == NULL) printf("ERR 2 file.bin\n");
    else {
        fread(&l,sizeof(int), 1, fp);
        fread(vet,sizeof(float), l, fp);
        fclose(fp);
    }
    
}

int ricerca(float vet[], int l, float ele) {
    int a = 0, b = l, m;
    do {
        m = (a+b)/2;
        if(vet[m] == ele) return m;
        else {
            if (vet[m]< ele)
                a = m+1;
            else
                b = m-1;
        }
    } while (a<=b);
    return -1;
} 

