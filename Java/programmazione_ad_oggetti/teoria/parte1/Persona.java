package programmazione_ad_oggetti.teoria.parte1;

public class Persona {
    String nome;
    String cognome;
    int eta;
    String colorePreferito;
    static int numeroPersone; // questo lo vedrai dal file Main9.java in poi

    // una funzione all'interno di una classe è un metodo
    void saluta() {
        System.out.println("Ciao, sono " + nome);
    }

    void cammina() {
        System.out.println("sto camminando...");
    }

    // vediamo come funziona il costruttore, ossia un metodo con lo stesso nome
    // della classe
    Persona(String nome, String cognome, int eta, String colorePreferito) {
        // per riferirci alle variabili di questa classe usiamo la parola chiave this
        this.nome = nome;
        this.cognome = cognome;
        this.colorePreferito = colorePreferito;
        this.eta = eta;

        // ricorda che lo scope delle variabili è stabilito da dove vengono definite. le
        // variabili definite dentro un metodo,
        // hanno scope locale al metodo
        // invece le variabili della classe hanno uno scope globale (sono accessibili in
        // tutta la classe)

        // vedi questa parte da Main9.java
        numeroPersone++; // questo è l'accesso di un attributo static (non dobbiamo usare this)
    }

    int addizione(int a, int b) {
        int risultato = a + b + this.eta;
        return risultato;
    }

    // int x = risultato; //errore perché non è visualizzabile la variabile

    // nei metodi possiamo usare parametri con lo stesso nome delle variabili della
    // classe, distinguendole dalla parola this
    // this.nome è diversa da nome

    public String toString() {
        String stringa = this.nome + " " + this.cognome + ", eta': " + this.eta + "\ncolore preferito: "
                + this.colorePreferito + "\n\n";
        return stringa;
    }

    void saluta(Persona personaDaSalutare) {
        System.out.println("Ciao " + personaDaSalutare.nome + ", io sono " + this.nome);
    }

    static void mostraNumeroPersone() {
        System.out.println("numero persone: " + numeroPersone);
    }

}
