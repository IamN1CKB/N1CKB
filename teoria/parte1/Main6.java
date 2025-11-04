package programmazione_ad_oggetti.teoria.parte1;

import java.util.ArrayList;

public class Main6 {
    public static void main(String[] args) {
        // le wrapped class consentono di utilizzare i tipi di dati primitivi come
        // reference
        // questo ci permette di usare i metodi sulle "primitive"
        // sono dunque primitive che vengono modificate come reference, ma che
        // rallentano il programma
        // sono tipi di dati molto più lenti rispetto alle primitive
        // ci basta scrivere durante la dichiarazione al posto di
        /*
         * boolean => Boolean
         * char => Character
         * int => Integer
         * double => Double
         */
        Boolean vero = true; // wrapped class come reference
        boolean falso = false; // primitiva

        Character carattere = 'a';
        Integer numero = 4;
        Double numeroVirgola = 4.5;
        // vedremo in futuro i metodi di questi
        // vediamo che vengono trattati come la stessa cosa, da questo paragone
        if (vero == !falso)
            System.out.println("sono la stessa cosa");

        // usiamo le altre variabili
        if (falso) {
            System.out.println(carattere);
            System.out.println(numero + numeroVirgola);

        }

        // vediamo cosa sono le array list: array ridimensionatili
        // accettano solo le reference type, quindi dovremo usare le wrapped class
        // per dichiararla dobbiamo scrivere
        // ArrayList<Type> nomeArrayList = new ArrayList<Type>();

        ArrayList<String> persone = new ArrayList<String>();
        // per aggiungere elementi usiamo il metodo .add
        persone.add("Luca");
        persone.add("Marco");
        persone.add("Anna");
        persone.add("Nicola");
        persone.add("Antonio");
        // per prendere un elemento usiamo il metodo .get(int index)
        System.out.println(persone.get(0));
        // per prendere la grandezza dell'arraylist dobbiamo usare il metodo .size()
        System.out.println("ArrayList di " + persone.size() + " elementi");
        // cicliamo l'arrayList
        for (int i = 0; i < persone.size(); i++) {
            System.out.println("Persona " + (i + 1) + ": " + persone.get(i));
        }

        // per modificare gli elementi dobbiamo usare il metodo .set(int index, Type
        // element)
        persone.set(2, "Paola");
        System.out.println();
        for (int i = 0; i < persone.size(); i++) {
            System.out.println("Persona " + (i + 1) + ": " + persone.get(i));
        }

        // possiamo rimuovere elementi con il metodo remove(int index)
        persone.remove(1);
        System.out.println();
        for (int i = 0; i < persone.size(); i++) {
            System.out.println("Persona " + (i + 1) + ": " + persone.get(i));
        }

        // per eliminare tutti gli elementi di un arrayList usiamo il metodo .clear()
        persone.clear();
        System.out.println("ci sono " + persone.size() + " persone");

        // non possiamo usare gli int semplici come primitive
        // ArrayList<int> numeri = new ArrayList<int>(); //errore
        ArrayList<Integer> numeri = new ArrayList<Integer>(); // con wrapped class va bene
        numeri.add(1);
        numeri.add(10);
        numeri.add(100);
        System.out.println();
        for (int i = 0; i < numeri.size(); i++) {
            System.out.println(numeri.get(i));
        }

        // per poter creare un'arrayList bidimensionale dobbiamo creare l'arrayList
        // delle righe, poi quello generale
        // abbastanza incasinato come dichiarazione
        ArrayList<ArrayList<String>> classi = new ArrayList<ArrayList<String>>();
        // questo è l'arraylist che conterrà le righe

        ArrayList<String> classe1 = new ArrayList<String>();
        classe1.add("Antonio");
        classe1.add("Nicola");
        classe1.add("Enza");
        ArrayList<String> classe2 = new ArrayList<String>();
        classe2.add("Giada");
        classe2.add("Gennaro");
        classe2.add("Umberto");
        classe2.add("Raffaele");

        // adesso aggiungiamo le righe nell'arrayList principale
        classi.add(classe1);
        classi.add(classe2);

        // mandiamo a schermo tutto l'array list bidimensionale
        for (int i = 0; i < classi.size(); i++) {
            for (int j = 0; j < classi.get(i).size(); j++) {
                System.out.println("classe " + (i + 1) + ", studente " + (j + 1) + ": " + classi.get(i).get(j));
            }
            System.out.println();
        }

    }
}
