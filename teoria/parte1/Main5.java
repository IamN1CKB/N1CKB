package programmazione_ad_oggetti.teoria.parte1;

public class Main5 {
    public static void main(String[] args) {
        // in questa lezione vedremo alcuni metodi delle stringhe
        String nome = "Nicola";
        boolean risultato = nome.equals("Leonardo");
        // compara nome con Leonardo (case sensitive, ossia sensibile alla maiuscole)
        System.out.println(risultato);

        System.out.println(nome.length()); // restituisce il numero di caratteri della stringa

        char lettera = nome.charAt(5); // lettera alla posizione 5 della stringa nome
        System.out.println(lettera);

        int posizione = nome.indexOf("l"); // ritorna l'indice della prima occorrenza della lettera o stringa cercata
        System.out.println(posizione);
        // nel caso in cui la lettera non c'è restituisce -1
        System.err.println(nome.indexOf("x"));

        risultato = nome.isEmpty(); // controlla se la stringa è vuota
        System.out.println(risultato);

        // per poter restituire le stringhe tutte in maiuscolo o in minuscolo abbiamo
        String nomeInMaiuscolo = nome.toUpperCase();
        System.out.println(nomeInMaiuscolo);
        System.out.println(nome.toLowerCase());

        // il metodo .trim consente di togliere gli spazi all'inizio e alla fine di una
        // stringa
        nome = "    Nick    ";
        System.out.println("|" + nome + "|");
        System.out.println("|" + nome.trim() + "|");

        // per sostituire tutte le occorrenze di una lettera con un altra lettera usiamo
        // replace
        nome = "Leonardo";
        System.out.println(nome.replace('o', 'w'));

        // per ottenere una sotto-stringa possiamo usare il metodo substring(int inizio,
        // int fine)
        nome = "pianoforte";
        System.out.println(nome.substring(5)); // "forte"
        System.out.println(nome.substring(5, 8)); // "for"

    }
}
