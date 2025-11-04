#include <stdio.h>
#define N 100
/*
copia di un file in un altro
*/
void main(){
    FILE *fp_in, *fp_out;
    char buf[N];
    int n;

    fp_in = fopen("file input", "r");
    if (fp_in == NULL) printf("il file input non è stato aperto correttamente");
    else {
        fp_out = fopen("file output", "w");
        if (fp_out == NULL) printf("il file output non è stato aperto correttamente");
        else {
            do {
                n = fread(buf, sizeof(char), N, fp_in);
                fwrite(buf, sizeof(char), n, fp_out);  //salviamo solo gli elementi che sono stati salvati nel buf, ossia n elementi
            } while (n>0);
            fclose(fp_out);
        }
        fclose(fp_in);
    }
    


}