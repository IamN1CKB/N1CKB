package programmazione_ad_oggetti.teoria.parte1;

public class Insegnante extends Persona {

    String materia = "matematica";
    String[] classi = { "1D", "3E", "5A" };

    Insegnante(String nome, String cognome, int eta, String colorePreferito) {
        super(nome, cognome, eta, colorePreferito);
    }

    void insegna() {
        System.out.println("sto insegnando...");
    }

    // facciamo l'override di saluta
    // va inserito il tag @override per comunicare al compilatore che il metodo che
    // trattiamo non è della classe figlia
    @Override
    void saluta() {
        System.out.println("Buongiorno classe");
    }

}
