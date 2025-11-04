package programmazione_ad_oggetti.esercizi.esami.maggio20_2024;

public class Alimentare implements Prodotto {
    private String codice;
    private String nome;
    private double prezzo;
    private int quantita;
    private String scadenza;

    Alimentare(String codice, String nome, double prezzo, int quantita, String scadenza) {
        this.codice = codice;
        this.nome = nome;
        this.prezzo = prezzo;
        this.quantita = quantita;
        this.scadenza = scadenza;
    }

    public String calcolaScadenzaRimanente() {
        return this.scadenza;
    }

    @Override
    public String toString() {
        return "Descrizione Alimentare\ncodice : " + this.codice + "\nnome : " + this.nome + "\nprezzo : " + this.prezzo
                + " euro\nquantità : " + this.quantita + "\nscadenza : " + this.scadenza;
    }

    @Override
    public String getCodice() {
        return this.codice;
    }

    @Override
    public String getNome() {
        return this.nome;
    }

    @Override
    public double getPrezzo() {
        return this.prezzo;
    }

    @Override
    public int getQuantita() {
        return this.quantita;
    }

    @Override
    public void setCodice(String codice) {
        this.codice = codice;
    }

    @Override
    public void setNome(String nome) {
        this.nome = nome;
    }

    @Override
    public void setPrezzo(double prezzo) {
        this.prezzo = prezzo;
    }

    @Override
    public void setQuantita(int quantita) {
        this.quantita = quantita;
    }

}
