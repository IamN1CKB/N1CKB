package programmazione_ad_oggetti.esercizi.esami.marzo17_2025;

import java.util.ArrayList;

public class GestioneContratti implements GestioneDati {
    ArrayList<Contratto> listaContratti = new ArrayList<Contratto>();
    double fatturatoTot;
    int veicoliVenduti;
    int veicoliNoleggiati;

    void aggiungiContratto(Contratto contratto) {
        this.listaContratti.add(contratto);
    }

    public void calcolaStatiche() {

    }

    public void stampaContratti() {
        for (Contratto contratto : listaContratti) {
            System.out.println(contratto);
        }
    }

    @Override
    public void leggiDaFile(String path) {
        // ? dov'è il file?
    }

    @Override
    public void scriviSuFile(String path) {
        // ? dov'è il file?

    }

}
