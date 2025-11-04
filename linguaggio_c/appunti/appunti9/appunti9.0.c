#include <stdio.h>
int main(){
    /*
    A ogni variabile corrisponde un nome, una locazione di memoria, e l’indirizzo della locazione di memoria. Il nome di 
    una variabile è il simbolo attraverso cui si fa riferimento al contenuto della corrispondente locazione di memoria.*/
    //Così, per esempio, nel frammento di programma:
    int g;
    g = 5;
    printf("%d\n", g);
    //viene assegnato il valore costante 5 alla variabile di tipo intero g.
    /*
    L’operatore unario di indirizzo &, introdotto con la funzione scanf, restituisce l’indirizzo di memoria di una variabile. Per esempio 
    l’espressione &g è un’espressione il cui valore è l’indirizzo della variabile g.
    */
    //possiamo vedere il valore del puntatore come indirizzo (in esadecimale) grazie al segnaposto %p
    printf("l'indirizzo di g in esadecimale = %p\n", &g);
    //potremmo vederlo anche come decimale, con il segnaposto %d
    /*
    Un indirizzo può essere assegnato solo a una speciale categoria di variabili dette puntatori,
    le quali sono appunto variabili abilitate a contenere un indirizzo. La sintassi di definizione è
        tipo_base *var_punt;
        va bene anche tipo_base* var_punt;
    dove var_punt è definita come variabile di tipo “puntatore a tipo_base”; in sostanza var_punt è creata per 
    poter mantenere l’indirizzo di variabili di tipo tipo_base, che è uno dei tipi fondamentali già introdotti: char, int,
    float e double. 

    Il tipo puntatore è un classico esempio di tipo derivato; infatti, non ha senso parlare di tipo puntatore in generale, ma 
    occorre sempre specificare a quale tipo esso punta. Per esempio, in questo caso:
    */
    int a = 7;
    char c = '.';
    int* pa;
    char* pc;
    pa = &a;   //puntatore di tipo a int
    pc = &c;   //puntatore di tipo a char
    printf("puntatore alla variabile intera a = %p\n", pa);


    //adesso introduciamo l'operatore che ci permette di vedere cosa contiene un indirizzo salvato in un puntatore,
    //ossia l'operatore unario *
    printf("a = %d\nc = %c\n\n\n", *pa, *pc); //*pa e *pc equivalgono a scrivere a e c
    //vediamo un altro esempio
    char c1, c2;
    //char *pc;  //già dichiarato
    c1 = 'a';
    c2 = 'b';
    printf("c1 = %c, c2 = %c \n", c1, c2);
    pc = &c1;      /* pc contiene l'indirizzo di c1 */
    c2 = *pc;      /* c2 contiene il carattere 'a' */
    printf("c1 = %c, c2 = %c \n\n\n", c1, c2);
    /*
    Dopo l’assegnazione pc=&c1; i nomi c1 e *pc sono perfettamente equivalenti (alias), e si può accedere allo stesso 
    oggetto creato con la definizione char c1 sia con il nome c sia con l’espressione *pc. L’effetto ottenuto con 
    l’assegnazione c2=*pc si sarebbe ottenuto, equivalentemente, con l’assegnazione
    c2 = c1;
    */

   //un ulteriore esempio di uso di puntatori e dell’operatore di dereferenziazione, riferiti a elementi di un array, è il seguente:
    int buf[2];
    int* p;

    p = &buf[1];
    *p = 4;
    /*
    Con il puntatore a intero p e l’operatore * si è modificato il contenuto della locazione di memoria buf[1], questa 
    volta preposta a contenere un valore di tipo int. 
  
  
    Il lettore avrà certo notato che l’operatore * è usato nella definizione di variabili di tipo “puntatore a”:
    int* pi;
    char* pc;
    inoltre ci viene ovvio pensare che se
    int a;
    int* p = &a;
    la condizione *p == a sarà sempre vera
    */

    //se vogliamo che il puntatore non abbia la possibilità di far cambiare il valore alla variabile puntata, possiamo dichiarare il puntatore come const
    int b=12;
    const int* punt = &b;
    //*punt2 = 11;      //darebbe errore
    printf("*punt = %d\n", *punt);

    //ATTENZIONE: non possiamo cambiare il valore della variabile puntata ma possiamo cambiare la variabile puntata
    int d = 11;
    punt = &d;
    printf("*punt = %d\n\n\n", *punt);


    //un puntatore può indicare a qualsiasi variabile, anche a un altro puntatore stesso. nel caso di un puntatore che punta a un altro puntatore abbiamo una dichiarazione del genere
    int** puntatore_a_p;
    //int* p;   gia sono state dichiarate in questo file
    //int a;
    p = &a;
    puntatore_a_p = &p;
    printf("l'indirizzo di a = %p\n", p);
    printf("l'indirizzo del puntatore che punta ad a = %p\n", puntatore_a_p);
    //in teoria si può anche prendere un indirizzo di un puntatore che punta a un altro puntatore che punta a un tipo semplice, come int
    //sarà molto raro che si richiede ma si può fare
    int*** puntatore_a_punt_a_p;
    puntatore_a_punt_a_p = &puntatore_a_p;
    printf("l'indirizzo del puntatore che punta al puntatore che punta ad a = %p\n", puntatore_a_punt_a_p);



    //spesso per comodità quando dichiariamo un puntatore senza che non punti ancora a nulla, lo inizializziamo a NULL
    int* z=NULL;  //va bene per puntatori a qualsiasi tipo
    if (z==NULL) printf("il puntatore z non punta a nessuna variabile\n");
    //l'indirizzo di NULL è l'indirizzo del primo elemento nel registro del processore, quindi se stampiamo z in questo caso ci dà tutti 0
    printf("indirizzo di NULL = %p\n", z);

    

}