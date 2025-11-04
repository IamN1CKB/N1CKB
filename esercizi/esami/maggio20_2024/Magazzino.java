package programmazione_ad_oggetti.esercizi.esami.maggio20_2024;

import java.util.ArrayList;

public class Magazzino {
    ArrayList<Prodotto> lista = new ArrayList<Prodotto>();

    public void aggiungiProdotto(Prodotto prodotto) {
        lista.add(prodotto);
    }

    public void rimuoviProdotto(Prodotto prodotto) throws Exception {
        for (int i = 0; i < lista.size(); i++) {
            if (lista.get(i).getCodice().equals(prodotto.getCodice())) {
                if (lista.get(i).getQuantita() > 1) {
                    lista.get(i).setQuantita(lista.get(i).getQuantita() - 1);
                    return;
                } else {
                    lista.remove(i);
                    return;
                }
            }
            if (i == lista.size() + 1)
                throw new Exception("Prodotto da eliminare non trovato");
        }
    }

    public Prodotto ricercaProdotto(String codice) throws Exception {
        for (int i = 0; i < lista.size(); i++) {
            if (codice.equals(lista.get(i).getCodice())) {
                return lista.get(i);
            }
        }
        throw new Exception("Prodotto non trovato");
    }

    public void stampaInfoProdotto(Prodotto prodotto) {
        System.out.println(prodotto.toString());
    }

    public void stampaScontrino() {
        double conto = 0;
        for (Prodotto prodotto : lista) {
            stampaInfoProdotto(prodotto);
            System.out
                    .println("costo prodotto: " + (conto += prodotto.getPrezzo() * prodotto.getQuantita()) + " euro\n");
        }
        System.out.println("Totale da pagare: " + conto + " euro");
    }

}
