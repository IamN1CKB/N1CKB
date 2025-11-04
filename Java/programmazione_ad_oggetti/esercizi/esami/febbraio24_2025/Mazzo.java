package programmazione_ad_oggetti.esercizi.esami.febbraio24_2025;

import java.util.ArrayList;

public class Mazzo {
    private ArrayList<Carta> carte = new ArrayList<Carta>();

    void caricaDaFile(String percorsoFile) {
        // legge le carte da un file CSV e le aggiunge al mazzo.
    }

    void mescola() {
        // mescola il mazzo utilizzando Collections.shuffle().

    }

    void pesca() {
        // pesca e rimuove la prima carta del mazzo.

    }

    public ArrayList<Carta> getCarte() {
        return carte;
    }

    public void setCarte(ArrayList<Carta> carte) {
        this.carte = carte;
    }

}
