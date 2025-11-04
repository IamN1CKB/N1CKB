package programmazione_ad_oggetti.teoria.parte2.Pacchetto2;

import programmazione_ad_oggetti.teoria.parte2.Pacchetto1.*; //importiamo tutto il pacchetto 1 in questo file (in cui c'è la classe A)

public class C extends A { // C classe figlia di A che si trova in un altro pacchetto

    B prova = new B();

    void stampa() {
        System.out.println(prova.nome);
        // non dà problemi ad accedere agli attributi della classe B siccome sono nello
        // stesso pacchetto

        // proviamo con eta, attributo di tipo protected
        System.out.println(eta);
        // non dà problemi siccome C è una classe figlia di A

    }
}
