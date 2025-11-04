#include <stdio.h>
#include <string.h>
#define N 200
struct MyStruct{
    char stringa[N];
    int indice;
};
typedef struct MyStruct Struct;

int n_parole(char str[]);

int nc_longWord(char str[]);

int n_maiuscole(char str[]);

int n_minuscole(char str[]);

void ordina_struct(Struct s[], int array[], int righe);

void salvaB(Struct s[], int righe);

int main() {
    Struct v[N];
    char buf[N];
    int righe = 0, mat[N][4];
    char *p;
                            memset(v,0,sizeof(Struct)*N);   //vedi ../README.md per capire
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) printf("ERR file\n");
    else {
        do {
            p = fgets(buf, N, fp);
            if (p != NULL){  //senza questo if l'ultima riga si ripeterebbe 2 volte
                if (buf[strlen(buf)-1] == '\n') buf[strlen(buf)-1] = '\0';     //sostituiamo lo \n finale con \0
                v[righe].indice = righe+1;
                strcpy(v[righe++].stringa, buf);
            }
        } while (p != NULL);
        
        fclose(fp);
    }

    for (int i = 0; i < righe; i++) {
        mat[i][0] = n_parole(v[i].stringa);
        mat[i][1] = nc_longWord(v[i].stringa);
        mat[i][2] = n_maiuscole(v[i].stringa);
        mat[i][3] = n_minuscole(v[i].stringa);
    }
    
    int array_nc[N];
    for (int i = 0; i < righe; i++)
        array_nc[i] = mat[i][1];

    
    ordina_struct(v, array_nc, righe);

    salvaB(v, righe);
    
}

int n_parole(char str[]) {
    int cont = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i]!= ' ' && (str[i+1] == ' '  || str[i+1] == '\0'))
            cont++;
    return cont;
}

int nc_longWord(char str[]) {
    int cont = 0, max = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i]==' ')
            cont = 0;
        else cont++;

        if (cont > max) max = cont;
    }

    return max;
}

int n_maiuscole(char str[]) {
    int cont = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i]>= 'A' && str[i]<= 'Z') cont++;
        
    return cont;
}

int n_minuscole(char str[]) {
    int cont = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i]>= 'a' && str[i]<= 'z') cont++;
        
    return cont;
}

void ordina_struct(Struct s[], int array[], int righe) {
    Struct struct_temp;
    int int_temp, condizione;
    do {
        condizione = 0;
        for (int i = 0; i < righe; i++) {
            if(array[i]<array[i+1]) {
                struct_temp = s[i];
                int_temp = array[i];
                s[i] = s[i+1];
                array[i] = array[i+1];
                s[i+1] = struct_temp;
                array[i+1] = int_temp;
                condizione = 1;
            }
        }
    } while (condizione); 
}

void salvaB(Struct s[], int righe) {
    FILE *fp = fopen("output.bin", "w");
    if (fp == NULL) printf("ERR file");
    else {
        fwrite(s,sizeof(Struct), righe, fp);
        fclose(fp);
    }
}