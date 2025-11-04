package programmazione_ad_oggetti.esercizi.esami.dicembre12_2023;

import java.util.ArrayList;

public class Concessionario {
    float guadagnoVendita;
    float guadagnoNoleggio;
    ArrayList<Veicolo> ListaVeicoli = new ArrayList<Veicolo>();

    public void aggiungiVeicolo(Veicolo veicolo) {
        this.ListaVeicoli.add(veicolo);
    }

    public void visualizzaInventario() {
        System.out.println("inventario completo con informazioni dei veicoli");
        for (Veicolo veicolo : ListaVeicoli)
            veicolo.descrizione();
    }

    public void acquistaVeicolo(Veicolo veicolo) {
        // vediamo il guadagno
        if (veicolo instanceof Auto)
            this.guadagnoVendita = this.guadagnoVendita + ((Auto) veicolo).getPrezzoVendita();
        if (veicolo instanceof Moto)
            this.guadagnoVendita = this.guadagnoVendita + ((Moto) veicolo).getPrezzoVendita();

        // eliminiamo il veicolo dall'inventario
        for (int i = 0; i < this.ListaVeicoli.size(); i++) {
            if (this.ListaVeicoli.get(i).equals(veicolo)) {
                this.ListaVeicoli.remove(i);
                return;
            }
        }
    }

    public void noleggiaVeicolo(Veicolo veicolo) {
        // vediamo il guadagno
        if (veicolo instanceof Moto)
            this.guadagnoNoleggio = this.guadagnoNoleggio + ((Moto) veicolo).getPrezzoNoleggio();
        if (veicolo instanceof Auto)
            this.guadagnoNoleggio = this.guadagnoNoleggio + ((Auto) veicolo).getPrezzoNoleggio();

        // eliminiamo il veicolo dall'inventario
        for (int i = 0; i < this.ListaVeicoli.size(); i++) {
            if (this.ListaVeicoli.get(i).equals(veicolo)) {
                this.ListaVeicoli.remove(i);
                return;
            }
        }

    }

    public float calcolaGuadagnoVendita() {
        return guadagnoVendita;
    }

    public float calcolaGuadagnoNoleggio() {
        return guadagnoNoleggio;
    }

    public float calcolaGuadagnoTotale() {
        return guadagnoVendita + guadagnoNoleggio;
    }

}
