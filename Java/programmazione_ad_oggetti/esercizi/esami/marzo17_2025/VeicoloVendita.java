package programmazione_ad_oggetti.esercizi.esami.marzo17_2025;

public class VeicoloVendita extends Veicolo {
    int anniGaranzia;
    boolean possFinanziamento;
    boolean nuovo;

    VeicoloVendita(String targa, String marca, String modello, int annoImmatricolazione, double prezzo,
            int anniGaranzia, boolean possFinanziamento, boolean nuovo) {
        super(targa, marca, modello, annoImmatricolazione, prezzo);
        this.anniGaranzia = anniGaranzia;
        this.possFinanziamento = possFinanziamento;
        this.nuovo = nuovo;
    }
}
