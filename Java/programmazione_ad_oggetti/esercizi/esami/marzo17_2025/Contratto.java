package programmazione_ad_oggetti.esercizi.esami.marzo17_2025;

public class Contratto {
    String data;
    String cliente;
    Veicolo veicolo;

    Contratto(String data, String cliente, Veicolo veicolo) {
        this.data = data;
        this.cliente = cliente;
        this.veicolo = veicolo;

    }

    @Override
    public String toString() {
        return "\ncliente: " + this.cliente + "\nveicolo: " + veicolo.toString();
    }
}
