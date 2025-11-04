package programmazione_ad_oggetti.esercizi.esami.dicembre12_2023;

public class Auto extends Veicolo {
    int porte;
    private float prezzoVendita;
    private float prezzoNoleggio;

    public Auto(String marca, String modello, int porte, float prezzoVendita, float prezzoNoleggio) {
        super(marca, modello);
        this.porte = porte;
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
        System.out.println("Descrizione Auto:");
        System.out.println("la marca è " + this.marca);
        System.out.println("il modello è " + this.modello);
        System.out.println("il numero di porte è " + this.porte);
        System.out.println("il prezzo di vendita è " + this.prezzoVendita + " euro");
        System.out.println("il prezzo di noleggio è " + this.prezzoNoleggio + " euro\n");
    }
}
