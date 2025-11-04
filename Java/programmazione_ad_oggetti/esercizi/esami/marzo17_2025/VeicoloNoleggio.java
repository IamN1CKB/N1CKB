package programmazione_ad_oggetti.esercizi.esami.marzo17_2025;

public class VeicoloNoleggio extends Veicolo {
    double tariffaGG; // tariffa giornaliera (prezzo al giorno)
    double cauzione;
    boolean assicurazioneInclusa;

    VeicoloNoleggio(String targa, String marca, String modello, int annoImmatricolazione, double tariffaGG,
            double cauzione, boolean assicurazioneInclusa) {
        super(targa, marca, modello, annoImmatricolazione, tariffaGG);
        // nella classe madre Veicolo c'è anche l'attributo prezzo, ma non c'è nel csv.
        // ci metto la tariffa giornaliera
        this.tariffaGG = tariffaGG;
        this.cauzione = cauzione;
        this.assicurazioneInclusa = assicurazioneInclusa;
    }
}
