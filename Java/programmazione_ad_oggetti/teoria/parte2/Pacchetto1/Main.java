package programmazione_ad_oggetti.teoria.parte2.Pacchetto1;

import programmazione_ad_oggetti.teoria.parte2.Pacchetto2.*; //importiamo tutto il pacchetto 2 (se volevamo importare solo un file non dovevamo mettere *)

public class Main {
    public static void main(String[] args) {
        // in questi file vedremo i modificatori di accesso, ossia le parole chiavi
        // public, protected, default, private
        /*
         * class package subclass world
         * public si si si si
         * protected si si si no
         * default si si no no
         * private si no no no
         */

        // questi modificatori di accesso servono per aggiungere un livello di sicurezza
        // aggiuntivo
        // infatti ci permettono di mostrare o meno determinati metodi e attributi nei
        // vari file di codice.
        // se ha un livello di sicurezza class vuol dire che possiamo usare l'attributo
        // o il metodo in una classe
        // se ha un livello di sicurezza package vuol dire che possiamo usare
        // l'attributo o il metodo all'interno dello stesso pacchetto
        // se ha un livello di sicurezza subclass vuol dire che possiamo usare
        // l'attributo o il metodo all'interno della classi figlie (anche fuori dal
        // pacchetto)
        // se ha un livello di sicurezza world vuol dire che possiamo usare l'attributo
        // o il metodo all'interno di tutto il codice
        B prova = new B();
        // System.out.println(prova.nome); //error
        // non abbiamo accesso al nome siccome la classe B fa parte di un altro
        // pacchetto rispetto a questo codice
        // e nome non ha nessuna keyword, ossia default (che non ha il livello di
        // sicurezza)

        // possiamo accedere agli attributi public anche di pacchetti esterni (a patto
        // che siano importati)
        System.out.println(prova.cognome);

        // proviamo ad accedere a un attributo protected dal pacchetto 1 (stesso
        // pacchetto del file)
        A prova2 = new A();
        System.out.println(prova2.eta);
        // adesso proviamo da un altro pacchetto
        // System.out.println(prova.colore); //non visibile perché da un altro pacchetto
        // adesso proviamo da un altro pacchetto ma con una classe figlia
        C classeFiglia = new C();
        System.out.println(classeFiglia.eta); // si può fare

        // System.out.println(C.boolean);
        // dà errore perché boolean ha un accesso default, che non consente l'accesso a
        // sottoclassi fuori dal pacchetto

        // gli attributi private non possono essere usati nemmeno nello stesso pacchetto
        // System.out.println(prova2.numeroPrivato); //errore

    }
}
