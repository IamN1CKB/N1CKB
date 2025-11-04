package programmazione_ad_oggetti.esercizi.esami.dicembre12_2023;

public class Moto extends Veicolo {
    int cilindrata;
    float prezzoVendita;
    float prezzoNoleggio;

    public Moto(String marca, String modello, int cilindrata, float prezzoVendita, float prezzoNoleggio) {
        super(marca, modello);
        this.cilindrata = cilindrata;
        this.prezzoVendita = prezzoVendita;
        this.prezzoNoleggio = prezzoNoleggio;
    }

    public void setPrezzoVendita(float prezzo) {
        this.prezzoVendita = prezzo;
    }

    public void setPrezzoNoleggio(float prezzo) {
        this.prezzoNoleggio = prezzo;
    }

    public float getPrezzoVendita() {
        return this.prezzoVendita;
    }

    public float getPrezzoNoleggio() {
        return this.prezzoNoleggio;
    }

    @Override
    public void descrizione() {
        System.out.println("Descrizione Moto:");
        System.out.println("la marca è " + this.marca);
        System.out.println("il modello è " + this.modello);
        System.out.println("la cilindrata è di " + this.cilindrata + " cavalli");
        System.out.println("il prezzo di vendita è " + this.prezzoVendita + " euro");
        System.out.println("il prezzo di noleggio è " + this.prezzoNoleggio + " euro\n");
    }

}
