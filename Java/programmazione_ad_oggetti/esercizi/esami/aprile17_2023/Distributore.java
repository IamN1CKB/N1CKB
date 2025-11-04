package programmazione_ad_oggetti.esercizi.esami.aprile17_2023;

public interface Distributore {
    public void aggiungiMoneta(String moneta);

    public void stampaCredito();

    public void acquistaProdotto(String codice);

    public void restituisciResto(float resto);

    public void stampaStock();

    public void modificaProdotto(Prodotto prodotto, boolean aggiungi);
}
