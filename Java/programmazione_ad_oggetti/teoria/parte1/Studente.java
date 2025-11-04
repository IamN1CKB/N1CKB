package programmazione_ad_oggetti.teoria.parte1;

public class Studente extends Persona {

    String materiaPreferita = "Storia";
    String classe = "3D";
    float votiStoria[] = { 9f, 8f, 7.5f };

    Studente(String nome, String cognome, int eta, String colorePreferito, String materiaPreferita) {
        super(nome, cognome, eta, colorePreferito);
        // super = sopra
        // questa funzione prende il costruttore della classe madre e fa ereditare gli
        // attributi
        // potremmo farlo manualmente con
        /*
         * this.nome = nome;
         * this.cognome =cognome; ...
         */

        // poi gli attributi propri della classe figlia vanno trattati a parte
        this.materiaPreferita = materiaPreferita;

    }

    void studia() {
        System.out.println("si mamma, sto studiando...");
    }

    // facciamo l'override di saluta.
    // va inserito il tag @override per comunicare al compilatore che il metodo che
    // trattiamo non è della classe figlia
    @Override
    void saluta() {
        System.out.println("Buongiorno prof!");

    }

}
