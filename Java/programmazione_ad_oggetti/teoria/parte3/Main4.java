package programmazione_ad_oggetti.teoria.parte3;

public class Main4 {
    public static void main(String[] args) {
        // in questa lezione vediamo il polimorfismo, ossia la capacità di un oggetto di
        // avere più forme
        // in questo caso ci riferiamo quindi a un oggetti che riesce a collegarsi a più
        // tipi di dato
        Studente studente1 = new Studente("Luca", "Rossi");
        Studente studente2 = new Studente("Anna", "Pepe");
        Insegnante insegnante1 = new Insegnante("Marco", "Verdi");
        // immaginiamo di voler fare un array che include sia studente1 che studente2
        // che insegnante1
        // sono oggetti diversi, quindi l'array come dovremmo dichiararlo?
        // Studente[] = {studente1, studente2, insegnante1}; //errore
        // Insegnante[] = {studente1, studente2, insegnante1}; //errore
        // dobbiamo usare la classe madre, ossia la classe Persona

        Persona[] classe = { studente1, studente2, insegnante1 };

        // vogliamo iterare con un foreach questo array, facendo salutare tutti
        for (Persona persona : classe) {
            persona.saluta();

        }

    }
}
