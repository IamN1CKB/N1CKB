package programmazione_ad_oggetti.teoria.parte4;

import java.util.HashMap;

public class Main3 {
    public static void main(String[] args) {
        // vediamo cosa sono le hash map
        // a differenza delle arrayList ci permettono di salvare come chiave valore
        // le arrayList sono un insieme valori iterati
        /*
         * In Java, una HashMap è una classe della libreria standard (java.util.HashMap)
         * che implementa la struttura dati di
         * una mappa basata su una tabella hash.
         * È utilizzata per memorizzare coppie chiave-valore, dove ogni chiave è unica e
         * mappa a un valore specifico.
         */
        HashMap<String, Integer> etaPersona = new HashMap<String, Integer>();
        etaPersona.put("Marco", 20);
        etaPersona.put("Maria", 23);
        etaPersona.put("Mattia", 26);
        etaPersona.put("Luigi", 29);
        System.out.println(etaPersona);
        String nome = "Mattia";
        System.out.println(nome + " ha " + etaPersona.get(nome) + " anni");
        etaPersona.remove(nome);
        System.out.println(etaPersona);
        etaPersona.clear();
        System.out.println(etaPersona);

    }
}
