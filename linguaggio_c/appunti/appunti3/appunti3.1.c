#include <stdio.h>
#include <math.h>
int main(){
    //variabili di tipo virgola mobile (i numeri reali)
    //i numeri che hanno una parte frazionario sono detti in virgola mobile (floating point) e non possono essere memorizzati come variabili di tipo int
    //possiamo memorizzare questi valori come float che di solito sono codificati in 4 byte, come le variabili int (può cambiare a seconda dell'implementazione)
    //Il formato standard per float in C, di solito, utilizza 32 bit (IEEE 754), di cui 1 bit per il segno, 8 bit per l'esponente e 23 bit per la mantissa. Questo consente la rappresentazione di numeri con una parte frazionaria e un ampio intervallo di valori sia piccoli che grandi, ma con una precisione limitata rispetto ai numeri interi o ai double il che può portare a errori di arrotondamento o approssimazione nei calcoli.
    //con 32 bit è possibile scrivere numeri il cui valore assoluto va da 3.4 * 10^(-38) a +3.4 * 10^(+38)
    float a = 0.5342;
    float b = -132453.908;   //valore che supera il valore massimo degli int
    float c = 7e+19;
    //la prima istruzione poteva essere scritta in questo modo: 
    //float a = .5342;
    //siccome lo zero prima del punto decimale può essere omesso
    //il valore di c è scritto in notazione esponenziale: la lettera e va interpretata come 10^ => c = 7*10^(+20)
    //la notazione esponenziale è comoda per mostrare il numero più compatto, ma avremmo anche potuto scrivere => 
    //c = 70000000000000000000;    //il valore non è cambiato

    //per visualizzare una variabile float in un istruzione printf() si deve specificare il segnaposto % con la lettera f se si vuole visualizzare il numero decimale in virgola mobile, oppure e se si vuole visualizzare il numero in notazione esponenziale
    printf("b = %e\n", b);
    printf("b = %f\n", b);
    printf("c = %e\n", c);
    printf("c = %f\n", c);    //non sarà preciso per via di un approssimazione dei float
    //come per gli interi si pò far seguire il segnaposto % con un numero che indica la lunghezza del campo
    //%x.yf     x sarebbe la lunghezza delle cifre intere, y la lunghezza delle cifre decimali
    //se x è minore delle cifre intere che ha il numero, vengono visualizzate lo stesso tutte
    //se y è minore delle cifre intere che ha il numero, vengono approssimate al numero con cifre decimali = y
    printf("b = %5.2f\n", b);
    printf("b = %.0f\n", b);    //in questo caso la parte decimale non viene visualizzata
    //c'è un ulteriore visualizzazione che sarebbe %g che decide la rappresentazione più breve tra numero decimale e notazione esponenziale
    b = 0.00003;
    printf("b = %g\n", b);  //in questo caso ha scelto la rappresentazione in notazione esponenziale

    //per rendere la rappresentazione dei numero reali ancora più precisa possiamo usare un altro tipo di virgola mobile in C, ossia il double, che generalmente occupano uno spazio di 8 byte (64 bit), e ciò permette di lavorare con i numeri il cui valore assoluto è tra 1.7e(-308) e 1.7e(+308)
    //un numero double migliora l'accuratezza dei numeri ma non assicura l'assenza di errori di arrotondamento
    //per poter visualizzare una variabile double in printf() possiamo usare il segnaposto %f oppure %lf (long float)
    double d = 5e+200;
    printf("%.0lf\n", d);    //ci sono comunque degli errori di approssimazione per rappresentare questi numeri in binario

    //possiamo verificare con quanti byte la nostra architettura del calcolatore memorizza una variabile a seconda del tipo, e possiamo farlo tramite l'operatore sizeof() che riporta i byte usati per memorizzare la variabile 
    int intero;
    printf("byte degli int: %d\n", sizeof(intero));
    char lettera;
    printf("byte dei char: %d\n", sizeof(lettera));
    float x;
    printf("byte dei float: %d\n", sizeof(x));
    double y;
    printf("byte dei double: %d\n", sizeof(y));
    //sizeof per la precisione non indica propriamente i byte, ma l’unità di misura di sizeof è il char e non il byte, come potrebbe venire naturale pensare.
    //quindi in ogni architettura sizeof(char) = 1 (dato che si usa quasi sempre la tabella ASCII per codificare i char, sono quasi sempre grandi un byte, e per questo coincide spesso con i byte)

    //OPERAZIONI IN VIRGOLA MOBILE
    //per adoperare delle operazioni matematiche usiamo la libreria math.h in cui sono definite varie funzioni che solitamente ricevono e restituiscono valori in double per essere più precisi.
    /*
        sin(x) seno
        cos(x) coseno
        tan(x) tangente
        sinh(x) seno iperbolico
        cosh(x) coseno iperbolico
        log(x) logaritmo in base e di x
        log10(x) logaritmo in base 10 di x
        sqrt(x) radice quadrata
    */

    //   ZERO DI UNA FUNZIONE DI VARIABILE REALE
    //per esercitarci con le strutture con i numeri reali possiamo prendere in considerazione il calcolo dello zero di una funzione con un metodo detto dicotomico.
    //data una funzione f(x) continua in un intervallo [a, b] e con f(a) e f(b) discordi, per il teorema degli zeri ci deve essere almeno uno zero.
    //cerchiamo di calcolarlo tramite il punto medio, ossia m, dell'intervallo: se m ha l'immagine = 0, allora m è uno zero della funzione. altrimenti verifichiamo con quale dei 2 estremi m è discorde, dopodiché continuiamo con lo stesso processo: troviamo il punto medio e vediamo se l'immagine è = 0 ...
    //proviamo a scrivere un codice che sia capace di trovare lo zero della funzione f(x)=2x^3 -4x + 1
    //float a, b;   //sono già dichiarati
    float m, fa, fb, fm;     //le variabili con f sono le immagini tramite la funzione
    //chiediamo all'utente di inserire i valori di a e b fin quando le loro immagini non sono discordi
    //lo deve fare almeno una volta, quindi ci è comodo usare un do while
    puts("calcolo dello zero della funzione f(x) = 2x^3 -4x + 1");
    do {
        puts("devi inserire gli estremi dell'intervallo fin quando le loro immagini non sono discorde");
        printf("inserisci il primo estremo a: ");
        scanf("%f", &a);
        printf("inserisci il secondo estremo b: ");
        scanf("%f", &b);
        fa = 2*(a*a*a) - 4*a +1;
        fb = 2*(b*b*b) - 4*b +1;
    } while (fa*fb>0);  //sono discordi fa e fb se il loro prodotto è < 0
    printf("f(a) = %f\n", fa);
    printf("f(b) = %f\n", fb);
    //calcoliamo lo zero della funzione verificando sempre il minimo e ci fermiamo quando siamo arrivati a un errore più piccolo di 0.001. dunque il valore assoluto dell'approssimazione dello zero deve essere <0.001.
    //per calcolare il valore assolto di un numero float usiamo la funzione fabs() simile ad abs() per gli int
    //usiamo sempre un do while siccome almeno una volta dobbiamo calcolare il minimo
    do {
        m = (a + b) / 2;
        fm = 2*(m*m*m) - 4*m +1;
        if (fm != 0) {  //se fm è diverso da 0 ci calcoliamo quale estremo ha l'immagine che è discorda all'immagine di m
            if (fa*fm > 0)  //in questo caso fa e fm sono concordi, e fb e fm sono discordi
                a = m;  //poniamo l'estremo a = m
            else // sono discordi fa e fm
                b = m;
            //mettiamo anche le loro immagini perché poi dovranno essere di nuovo paragonate   
        }
    } while (fabs(fm) > 0.001);
    printf("lo zero è x = %7.2f\n", m);
    //ci sono 3 zeri di questa funzione (puoi vedere qui https://www.desmos.com/calculator/0m6tvg3rps)
    //per questo il programma può trovare 3 zeri che sono x = 0.26, x = -1.53, x = 1.27


    //con questo stesso metodo per trovare lo zero di una funzione, possiamo ricavarci la radice ennesima di un numero trovando lo zero della funzione potenza ennesima
    //partiamo per gradi e cerchiamo di calcolare la radice cubica di 2
    //abbiamo dunque la funzione f(x) = x^3 - 2 il cui zero è la radice cubica di 2
    //troviamo lo zero di questa funzione
    puts("calcolo dello zero della funzione f(x) = x^3 - 2");
    
    //decidiamo gli estremi dell'intervallo fin quando le loro immagini non sono discorde
    //sappiamo che la funzione in f(0) deve essere per forza negativa, invece in f(2) deve essere per forza positiva
    //consideriamo questi 2 estremi allora
    a = 0;
    b = 2;
    fa = a*a*a -2;
    fb = b*b*b -2;
    do {
        m  = (a+b)/2;
        fm = m*m*m -2;
        if (fm!=0) {
            if (fa*fm > 0)  //f(a) e f(m) sono concordi   =>   f(m) e f(b) sono discordi 
                a = m;
            else       //f(a) e f(m) sono discordi
                b = m;
        }
    } while (fabs(fm) > 0.0001);
    printf("La radice cubica di 2 e': %f\n", m);

    //adesso generalizziamo questo codice per trovare la radice cubica di qualsiasi numero <= -1 || numero >= 1
    do {
        printf("scegli un numero di cui fare la radice cubica (n <= -1 || n >= 1): ");
        scanf("%f", &b);
    } while (-1<b && b<1);
    
    float b1 = b;   //dato che il valore di b cambierà, ci salviamo il valore iniziale in questa variabile
    a = 0;
    fa = a*a*a - b1;
    fb = b*b*b - b1;
    do {
        m  = (a+b)/2;
        fm = m*m*m - b1;
        if (fm!=0) {
            if (fa*fm > 0)  //f(a) e f(m) sono concordi   =>   f(m) e f(b) sono discordi 
                a = m;
            else       //f(a) e f(m) sono discordi
                b = m;
        }
    } while (fabs(fm) > 0.00001);
    printf("La radice cubica di %f è: %f\n", b1, m);


    //adesso proviamo a generalizzare ulteriormente questo programma per trovare la radice ennesima di un numero b inserito dall'utente
    // b <= -1 || b >= 1
    //f(x) = x^n - b   =>      f(x) = 0     =>      b=x^n   
    int n;
    do {
        printf("Inserisci l'indice di radice (numero naturale > 1): ");
        scanf("%d", &n);
        printf("Inserisci il radicando (numero reale): ");
        scanf("%f", &b);
    } while (n<=1 || (-1<b && b<1));
    
    b1 = b;   //dato che il valore di b cambierà, ci salviamo il valore iniziale in questa variabile
    a = 0;
    fa = -b1;   //0*0*0 - b1
    fb = b1;    //inizialmente lo poniamo a b1 poi, facciamo la potenza tramite il ciclo for
    for (int i = 1; i < n; i++) fb *= b1; //questo ciclo modifica fb = b1 * b1^(n-1) = b1^(1+n-1) = b1^n
    fb -= b1;   //sappiamo che f(x) = x^n - b1

    do {
        m  = (a+b)/2;
        fm = m;
        for (int i = 1; i < n; i++) fm *= m;
        fm -= b1;
        
        if (fm!=0) {
            if (fa*fm > 0)  //f(a) e f(m) sono concordi   =>   f(m) e f(b) sono discordi 
                a = m;
            else       //f(a) e f(m) sono discordi
                b = m;
        }
    } while (fabs(fm) > 0.0001);
    printf("La radice ennesima (%d) di %f è: %f", n, b1, m);

    
}//vai a prossima lezione