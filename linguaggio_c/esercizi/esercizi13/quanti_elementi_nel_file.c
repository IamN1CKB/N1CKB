#include <stdio.h>
#define N 100
struct myStruct {
    int valore_a_caso;
    float valore_a_cas;
    char boh[50]; 
};
typedef struct myStruct MyStruct;

int main(){
    //abbiamo il file file1/vetStruct.bin che contiene un vettore di struct del tipo nominato in questo programma, ma vogliamo capire quanti elementi del vettore di struct ci sono nel file
    MyStruct buf;
    int n, cont = 0;
    //usiamo un ciclo do while in cui leggiamo una struct alla volta del vettore e vediamo quando fread riporta 0, ossia quando ha finito di leggere
    FILE *fp = fopen("file1/vetStruct.bin", "r");
    if (fp == NULL){
        printf("ERR\n");
        return 0;
    }
    
    n = fread(&buf, sizeof(MyStruct), 1, fp);
    while (n != 0) {
        n = fread(&buf, sizeof(MyStruct), 1, fp);
        cont++;
    }
    printf("elementi del vettore nel file = %d\n", cont);   //sono 7 elementi
    fclose(fp);
}
