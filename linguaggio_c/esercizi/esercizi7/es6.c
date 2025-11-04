#include <stdio.h>
#include <math.h>
/*
Modificare il programma che calcola uno zero della funzione matematica f(x) = 2x^3 - 4x + 1, in modo che utilizzi una
funzione per determinare i valori di f.
*/
#define ERR 0.00001
void estremi_discordi();
double zero_funzione();
double a, b, fa, fb;

void main() {
    printf("calcolo degli zeri della funzione => f(x) = 2x^3 - 4x + 1\n");
    estremi_discordi();
    zero_funzione();
    printf("uno zero della funzione è %lf", zero_funzione());
}

void estremi_discordi() {
    do {
        printf("inserisci primo estremo dell'intervallo: ");
        scanf("%lf", &a);
        printf("inserisci secondo estremo dell'intervallo: ");
        scanf("%lf", &b);

        fa = 2*a*a*a-4*a+1;
        fb = 2*b*b*b-4*b+1;
    } while (fa*fb>0 && a>=b);
}

double zero_funzione() {
    double fm, m;
    do {
        fa = 2*a*a*a-4*a+1;
        fb = 2*b*b*b-4*b+1;

        m = (a+b)/2;
        fm = 2*m*m*m-4*m+1;
        if (fm*fa>0) a = m;
        else b = m;

    } while (fabs(fm)>ERR);
    return m;
}