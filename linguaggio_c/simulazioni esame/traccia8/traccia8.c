//sesta traccia su parsec
#include <stdio.h>
#include <string.h>
#define N 100
struct myStruct{
    int pos;
    char c;
    int l;
};
typedef struct myStruct MyStruct;

int leggiStr(char str[], char *file);
int fParole(char str[], MyStruct s[]);
void stampaStruct(MyStruct s[], int parole);
void ordinaStruct(MyStruct s[], int n);
int salvaB(MyStruct s[], int n);
int main() {
    char str[N];
    int len, parole;
    MyStruct vetStr[N/2];
    memset(vetStr, 0, sizeof(MyStruct)*N/2);
    if (leggiStr(str, "input.txt")==-1){
        printf("ERR file input");
        return 0;
    }
    len = strlen(str);
    str[--len] = '\0';  //len = lunghezza escluso \0
    printf("%s\n\n\n", str);
    parole = fParole(str, vetStr);
    
    stampaStruct(vetStr, parole);
    ordinaStruct(vetStr, parole);
    
    stampaStruct(vetStr, parole);
    
    if (salvaB(vetStr, parole) == -1){
        printf("ERR file output.bin");
        return 0;
    }
    

}
int salvaB(MyStruct s[], int n) {
    FILE *fp = fopen("output.bin", "w");
    if (fp == NULL) return -1;
    else {
        fwrite(s, sizeof(MyStruct), n, fp);
        fclose(fp);
        return 1;
    }
    
}
void ordinaStruct(MyStruct s[], int n) {
    MyStruct temp;
    int condizione;
    do {
        condizione = 0;
        for (int i = 0; i < n-1; i++) {
            if (s[i].l>s[i+1].l) {
                temp = s[i];
                s[i] = s[i+1];
                s[i+1] = temp;
                condizione = 1;
            }
            else {
                if ((s[i].l == s[i+1].l) && (s[i].pos>s[i+1].pos)) {
                    temp = s[i];
                    s[i] = s[i+1];
                    s[i+1] = temp;
                    condizione = 1;
                }
            }
        }
    } while (condizione);
    
}

void stampaStruct(MyStruct s[], int parole) {
    for (int i = 0; i < parole; i++){
        printf("PAROLA n %d\n", i+1);
        printf("lunghezza parola = %d\n", s[i].l);
        printf("la posizione iniziale = %d\n", s[i].pos);
        printf("tipo parola = %c\n\n\n\n\n", s[i].c);
    }
}


int fParole(char str[], MyStruct s[]) {
    int parola = 0, parole = 0, n_caratteri = 0;
    char tipo_parola;
    for (int i = 0; str[i]!='\0'; i++) {
        if (parola == 0) {
            if (str[i] != ' ') {
                s[parole].pos = i;
                n_caratteri++;
                parola = 1;
                if ((str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z'))
                    tipo_parola = 'a';
                else tipo_parola = 'c';
            }
        }
        else {
            if ((str[i] != ' ') && (str[i+1] == ' ' || str[i+1] == '\0')) {
                if (((tipo_parola == 'a') && !((str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z')))||((tipo_parola == 'c') && ((str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z'))))
                    tipo_parola = 'b';
                n_caratteri++;
                s[parole].l = n_caratteri;
                s[parole].c = tipo_parola;
                n_caratteri = 0;
                parola = 0;
                parole++;
            }
            else {
                if (((tipo_parola == 'a') && !((str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z')))||((tipo_parola == 'c') && ((str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z'))))
                    tipo_parola = 'b';
                n_caratteri++;
            }
        }
    }
    return parole;
}



int leggiStr(char str[], char *file) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) return -1;
    else {
        fgets(str, N, fp);
        fclose(fp);
    }
}