package programmazione_ad_oggetti.esercizi.esami.febbraio24_2025;

public class CartaPokemon extends Carta {
    private int puntiVita;
    private int puntiVitaIniziali;
    private int attacco;
    private int energiaNecessaria; // energia necessaria per attaccare
    private int energiaAssegnata;

    void assegnaEnergia(CartaEnergia energia) {
        // aggiunge energia al Pokemon se compatibile
    }

    void subisciDanni(int attacco) {

    }

    public void setAttacco(int attacco) {
        this.attacco = attacco;
    }

    public void setEnergiaAssegnata(int energiaAssegnata) {
        this.energiaAssegnata = energiaAssegnata;
    }

    public void setEnergiaNecessaria(int energiaNecessaria) {
        this.energiaNecessaria = energiaNecessaria;
    }

    public void setPuntiVita(int puntiVita) {
        this.puntiVita = puntiVita;
    }

    public void setPuntiVitaIniziali(int puntiVitaIniziali) {
        this.puntiVitaIniziali = puntiVitaIniziali;
    }

    public int getAttacco() {
        return attacco;
    }

    public int getEnergiaAssegnata() {
        return energiaAssegnata;
    }

    public int getEnergiaNecessaria() {
        return energiaNecessaria;
    }

    public int getPuntiVita() {
        return puntiVita;
    }

    public int getPuntiVitaIniziali() {
        return puntiVitaIniziali;
    }

}
