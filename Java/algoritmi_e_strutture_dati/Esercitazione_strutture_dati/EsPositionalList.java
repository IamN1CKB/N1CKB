package algoritmi_e_strutture_dati.Esercitazione_strutture_dati;

import java.util.Iterator;

import algoritmi_e_strutture_dati.Strutture_dati.LinkedPositionalList;
import algoritmi_e_strutture_dati.Strutture_dati.Position;

public class EsPositionalList {
    public static void main(String[] args) {
        LinkedPositionalList<String> listaPosizioni = new LinkedPositionalList<String>();
        Position<String> MichelePosition = listaPosizioni.addFirst("Michele");
        // lista: Michele
        Position<String> LucaPosition = listaPosizioni.addFirst("Luca");
        // lista: Luca, Michele
        System.out.println("numero elementi lista posizionale: " + listaPosizioni.size());
        System.out.println("primo elemento della lista posizionala: " + listaPosizioni.first().getElement());
        System.out.println("elemento Michele della lista posizionala: " + MichelePosition.getElement());
        System.out.println("elemento Luca della lista posizionala: " + LucaPosition.getElement());
        // rimuoviamo Luca dalla lista
        listaPosizioni.remove(LucaPosition);
        // lista: Michele
        System.out.println("numero elementi lista posizionale: " + listaPosizioni.size());
        try {
            // se proviamo a stampare un elemento rimosso (Luca), ci dà IllegalStateException
            System.out.println("elemento Luca della lista posizionala: " + LucaPosition.getElement());
        } catch (Exception e) {
            System.out.println("\n");
            e.printStackTrace();
            System.out.println("\n");
        }
        System.out.println("elemento Michele della lista posizionala: " + MichelePosition.getElement());
        Position<String> MarioPosition = listaPosizioni.addAfter(MichelePosition, "Mario");
        // lista: Michele, Mario
        System.out.println("elemento Mario della lista posizionala: " + MarioPosition.getElement());
        try {
            // se proviamo ad aggiungere una posizione prima o dopo una posizione che è
            // stata rimossa dalla lista, ci darà IllegalArgumentException
            Position<String> LuigiPosition = listaPosizioni.addBefore(LucaPosition, "Luigi");
            System.out.println(LuigiPosition.getElement());
        } catch (Exception e) {
            System.out.println("\n");
            e.printStackTrace();
            System.out.println("\n");
        }

        Position<String> LuigiPosition = listaPosizioni.addBefore(MichelePosition, "Luigi");
        // lista: Luigi, Michele, Mario
        System.out.println("elemento Luigi della lista posizionala: " + LuigiPosition.getElement());

        System.out.println("stampa con iteratore esplicito della lista posizionale:");
        Iterator<String> iter = listaPosizioni.iterator();
        while (iter.hasNext()) {
            String variabile = iter.next();
            System.out.println(variabile);
        }

        // proviamo a iterare con un for each
        System.out.println("stampa con for each della lista posizionale:");
        for (String s : listaPosizioni) {
            System.out.println(s);
        }

        System.out.println(
                MarioPosition.getElement() + " e' dopo di " + listaPosizioni.before(MarioPosition).getElement());



    
        // 1. Istanziazione della lista posizionale
        LinkedPositionalList<String> listapos = new LinkedPositionalList<>();

        // 2. Definizione dei dati e popolamento
        String[] testo = {"primo", "secondo", "terzo"};
        System.out.println("Avvio lista");

        for (String s : testo) {
            listapos.addLast(s);
        }

        // 3. Sostituzione dell'elemento di testa
        String s1 = "primonuovo";
        listapos.set(listapos.first(), s1);

        // 4. Stampa dei metadati di base
        System.out.println("Dimensione lista= " + listapos.size());
        System.out.println("Primo lista= " + listapos.first().getElement());

        Position<String> p = listapos.after(listapos.first());
        System.out.println("Elemento successivo al primo= " + p.getElement());
        System.out.println(); // Spaziatore logico

        // 5. ATTREVERSAMENTO 1: Iteratore classico di elementi (ElementIterator)
        Iterator<String> iterr = listapos.iterator();
        while (iterr.hasNext()) {
            System.out.println("Valore nella lista= " + iterr.next());
        }
        System.out.println(); // Spaziatore logico

        // 6. ATTRAVERSAMENTO 2: Iteratore in avanti delle posizioni (positions())
        Iterable<Position<String>> iter2 = listapos.positions();
        for (Position<String> p1 : iter2) {
            System.out.println("Valore nella lista per posizione = " + p1.getElement());
        }
        System.out.println(); // Spaziatore logico

       // 7. ATTRAVERSAMENTO 3: Iteratore a ritroso delle posizioni (positionsB())
       Iterable<Position<String>> iterB = listapos.positionsB();
       for (Position<String> p1 : iterB) {
           System.out.println("Valore nella lista per posizione a ritroso = " + p1.getElement());
       }
    }
}
