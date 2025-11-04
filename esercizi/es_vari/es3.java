package programmazione_ad_oggetti.esercizi.es_vari;

public class es3 {
    // commento su una riga

    /*
     * commento
     * multi
     * riga
     */

    /**
     * commenti di documentazione multiriga
     */

    int x = 5; // variabile intera
    final int posti = 27; // final indica una costante
    // possiamo definire una blanck final, ossia una variabile costante non ancora
    // inizializzata,
    // ma che una volta inizializzata diviene costante

    // casting implicito a un tipo più capiente viene assegnato un tipo meno
    // capiente
    int i = 24;
    long n = i;
    // casting esplicito
    float y = (float) i;
    // non possibili di casting boolean-intero

    // vedi operatore ternario
    int a = y == 0 ? 5 : 6;

    String s1 = new String("a");
    String s2 = new String("b");

}
