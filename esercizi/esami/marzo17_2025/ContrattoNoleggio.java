package programmazione_ad_oggetti.esercizi.esami.marzo17_2025;

public class ContrattoNoleggio extends Contratto {
    String dataInizio;
    String dataFine;
    double importoTotale;

    ContrattoNoleggio(String data, String cliente, VeicoloNoleggio veicolo, String dataInizio, String dataFine,
            double importoTotale) {
        super(data, cliente, veicolo);
        this.dataInizio = dataInizio;
        this.dataFine = dataFine;
        this.importoTotale = importoTotale;
    }

    @Override
    public String toString() {
        return "Noleggio," + this.dataInizio + "," + this.dataInizio + "\n" + super.toString() + "tariffa: "
                + ((VeicoloNoleggio) veicolo).tariffaGG + "€/giorno, Totale: " + importoTotale + "\nAssicurazione: "
                + (((VeicoloNoleggio) veicolo).assicurazioneInclusa ? "inclusa" : "non inclusa") + "\n\n";
    }

}
