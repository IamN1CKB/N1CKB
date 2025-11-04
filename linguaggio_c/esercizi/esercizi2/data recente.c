#include <stdio.h>
/*
 Scrivere il programma che, richiesti sei numeri che rappresentano due date nel formato GG, MM, AA, determini quella che viene prima (in futuro fallo con le funzioni)
*/
int main() {
    int GG, MM, AA, boolean;
    int gg, mm, aa, boolean2;
    puts("Dobbiamo confrontare 2 date");
    printf("inserisci i numeri di giorno, mese e anno della prima data (separati da uno /): ");
    scanf("%d/%d/%d", &GG, &MM, &AA);
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
        puts("Data 1 accettata");
    else {
        puts("Data 1 errata");
        return -1;
    }

    
    printf("inserisci i numeri di giorno, mese e anno della seconda data (separati da uno /): ");
    scanf("%d/%d/%d", &gg, &mm, &aa);
    if (mm>=1 && mm<=12) {
        if (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12) {
            if (gg<= 31 && gg>=1)
                boolean=1;
            else
                boolean=0;
        }
        else if (mm==4 || mm==6 || mm==9 || mm==11) {
            if (gg<= 30 && gg>=1)
                boolean = 1;
            else
                boolean=0;
        }
        else if (mm==2) {
            if (aa % 4 == 0 && aa % 100 != 0) {
                if (gg>=1 && gg<=29)
                    boolean = 1;
                else
                    boolean = 0;
            }
            else {
                if (gg>=1 && gg<=28)
                    boolean = 1;
                else
                    boolean = 0;
            }
        }
    }
    else
        boolean=0;
    if (boolean)
        puts("Data 1 accettata");
    else {
        puts("Data 1 errata");
        return -1;
    }


    puts("confrontiamo la data piu' recente");
    if (AA>aa)
        printf("data 2 viene prima\n");
    else if (AA<aa)
        printf("data 1 viene prima\n");
    else {
        if (MM>mm)
            printf("data 2 viene prima\n");
        else if (MM<mm)
            printf("data 1 viene prima\n");
        else {
            if (GG>gg)
                printf("data 2 viene prima\n");
            else if (GG<gg)
                printf("data 1 viene prima\n");
            else
                printf("Le due date sono identiche\n");
        }
    }
}