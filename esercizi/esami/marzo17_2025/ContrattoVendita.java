package programmazione_ad_oggetti.esercizi.esami.marzo17_2025;

public class ContrattoVendita extends Contratto {
    double sconto;
    String modPagamento;
    double prezzoFinale;

    ContrattoVendita(String data, String cliente, VeicoloVendita veicolo, double sconto, String modPagamento,
            double prezzoFinale) {
        super(data, cliente, veicolo);
        this.sconto = sconto;
        this.modPagamento = modPagamento;
        this.prezzoFinale = prezzoFinale;
    }

    @Override
    public String toString() {

        return "Vendita," + this.data + "\n" + super.toString() + "Prezzo: " + this.prezzoFinale + "€ (Sconto: "
                + (prezzoFinale - veicolo.prezzo) + ")\nModalità di pagamento: " + modPagamento + "\n\n";
    }
}
