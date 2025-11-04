#include <stdio.h>
/*
Scrivere un programma che, richiesti i numeri GG, MM, AA di una data, verifichi se questa è valida.
*/
int main(){
    int boolean;
    int GG, MM, AA;
    printf("inserisci i numeri di Giorno, mese e anno separati da uno spazio: ");
    scanf("%d %d %d", &GG, &MM, &AA);
    if (MM>=1 && MM<=12) {
        if (MM==1 || MM==3 || MM==5 || MM==7 || MM==8 || MM==10 || MM==12) {
            if (GG<= 31 && GG>=1)
                boolean=1;
            else
                boolean=0;
        }
        else if (MM==4 || MM==6 || MM==9 || MM==11) {
            if (GG<= 30 && GG>=1)
                boolean = 1;
            else
                boolean=0;
        }
        else if (MM==2) {
            if (AA % 4 == 0 && AA % 100 != 0) {
                if (GG>=1 && GG<=29)
                    boolean = 1;
                else
                    boolean = 0;
            }
            else {
                if (GG>=1 && GG<=28)
                    boolean = 1;
                else
                    boolean = 0;
            }
        }
    }
    else
        boolean=0;

    if (boolean)
        puts("Data accettata");
    else
        puts("Data errata");
}