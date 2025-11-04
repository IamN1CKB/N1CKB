#include <stdio.h>
#define N 100
struct myStruct{
	int position;
	int value;
};
typedef struct myStruct MyStruct;

void leggiV(int vet[], int *l);

void salvaB(MyStruct s[], int l);

void ordinamento(int s[], int l);

int main(){
    int vet[N], l;
    MyStruct s[N];
    memset(s, 0, sizeof(MyStruct)*N);
    leggiV(vet, &l);
    ordinamento(vet, l);

    for (int i = 0; i < l; i++) {
        s[i].position = i;
        s[i].value = vet[i];
    }


    salvaB(s, l);
}

void leggiV(int vet[], int *l) {
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) printf("ERR file input.txt\n");
    else {
        fscanf(fp, "%d", l);
        for (int i = 0; i < *l; i++)
            fscanf(fp, "%d", &vet[i]);
        fclose(fp);
    }   
}

void salvaB(MyStruct s[], int l){
    FILE *fp = fopen("output.bin", "w");
    if (fp == NULL) printf("ERR file output.bin\n");
    else {
        fwrite(s, sizeof(MyStruct), l, fp);
        fclose(fp);
    }
}

void ordinamento(int s[], int l) {
    int condizione, p, temp;
    do {
        condizione = 0;
        for (int i = 0; i < l-1; i++){
            if (s[i]>s[i+1]) {
                temp = s[i];
                s[i] = s[i+1];
                s[i+1] = temp;
                condizione = 1;
                p = i+1;
            }
        }
        l = p;
    } while (condizione);
}