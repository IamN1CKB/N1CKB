package programmazione_ad_oggetti.teoria.parte1;

import java.util.Scanner; //importiamo la libreria che ci permette di usare lo Scanner, che serve per leggere da console

public class Main2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // usiamo una variabile di tipo reference, ossia Scanner
        // questa variabile ci è utile per leggere i caratteri inseriti da tastiere
        // sulla consola
        System.out.println("inserisci il tuo nome:");
        String nome = scanner.nextLine(); // il metodo nextLine legge tutta la riga fino all'invio.
        System.out.println("ciao " + nome); // l'addizione di 2 stringhe viene considerata come concatenazione
        System.out.println("qual e' la tua eta'?");
        int eta = scanner.nextInt(); // il metodo nextInt legge tutto il numero fino al prossimo spazio

        // nella lettura delle prossime cose da terminale avremmo dei problemi
        /*
         * Il problema principale nel tuo codice è che dopo scanner.nextInt(), rimane un
         * carattere di nuova
         * riga (\n) nel buffer, il che fa sì che scanner.nextLine() venga saltato.
         * Per risolvere questo problema, devi aggiungere un scanner.nextLine() subito
         * dopo scanner.nextInt()
         * per consumare il carattere di nuova riga.
         */

        scanner.nextLine();
        System.out.println("in che citta' vivi?");
        String citta = scanner.nextLine();

        System.out.print("ciao " + nome + ". Tu vivi a " + citta + " e ");
        // vediamo un if statement (che già conosciamo dal linguaggio c)
        if (eta >= 18)
            System.out.println("sei maggiorenne");
        else
            System.out.println("sei minorenne");

        scanner.close(); // bisogna chiudere lo scanner per non lasciare il canale aperto con il
                         // terminale

        // in questa lezione vedremo la classe Math per operazioni più complesse come:
        // abs, min, max, pow, sqrt
        // vedremo in futuro cos'è una classe
        System.out.println(Math.abs(-55)); // modulo
        System.out.println(Math.min(-55, 10)); // minimo di un array di valori
        System.out.println(Math.max(-55, 10)); // massimo di un array di valori
        System.out.println(Math.pow(5, 2)); // potenza di un numero (base, esponente)
        System.out.println(Math.sqrt(25)); // radice quadrata di un numero
        System.out.println(Math.PI); // valore del pi greco
        // ci sono vari altre funzioni che si possono trovare nella documentazione
    }
}
