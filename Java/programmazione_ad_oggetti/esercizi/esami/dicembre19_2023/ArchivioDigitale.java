package programmazione_ad_oggetti.esercizi.esami.dicembre19_2023;

import java.util.ArrayList;

public class ArchivioDigitale {
    ArrayList<ElementoArchivio> elementiArchivio = new ArrayList<ElementoArchivio>();

    public void aggiungiElemento(ElementoArchivio elemento) {
        elementiArchivio.add(elemento);

    }

    public void visualizzaArchivio() {
        for (ElementoArchivio elementoArchivio : elementiArchivio) {
            elementoArchivio.visualizzaDettagli();
        }
    }
}
