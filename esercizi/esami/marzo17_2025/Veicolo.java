package programmazione_ad_oggetti.esercizi.esami.marzo17_2025;

public class Veicolo {
    String targa;
    String marca;
    String modello;
    int annoImmatricolazione;
    double prezzo;

    Veicolo(String targa, String marca, String modello, int annoImmatricolazione, double prezzo) {
        this.targa = targa;
        this.marca = marca;
        this.modello = modello;
        this.annoImmatricolazione = annoImmatricolazione;
        this.prezzo = prezzo;
    }

    @Override
    public String toString() {
        return this.marca + this.modello + "(" + this.targa + ")";
    }
}
