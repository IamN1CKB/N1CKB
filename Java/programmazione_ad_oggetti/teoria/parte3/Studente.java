package programmazione_ad_oggetti.teoria.parte3;

public class Studente extends Persona {
    Studente(String nome, String cognome) {
        super(nome, cognome);
    }

    @Override
    public void saluta() {
        System.out.println("Buongiorno prof");
    }
}
