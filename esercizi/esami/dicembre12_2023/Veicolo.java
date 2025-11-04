package programmazione_ad_oggetti.esercizi.esami.dicembre12_2023;

public class Veicolo {
    String marca;
    String modello;

    public Veicolo(String marca, String modello) {
        this.marca = marca;
        this.modello = modello;
    }

    public void descrizione() {
        System.out.println("la marca è " + this.marca);
        System.out.println("il modello è " + this.modello);
    }

}
