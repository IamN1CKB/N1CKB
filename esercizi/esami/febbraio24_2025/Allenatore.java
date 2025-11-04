package programmazione_ad_oggetti.esercizi.esami.febbraio24_2025;

import java.util.ArrayList;

public class Allenatore {
    private String nome;
    private Mazzo mazzo = new Mazzo();
    private ArrayList<Carta> mano = new ArrayList<Carta>();
    private CartaPokemon pokemonAttivo;

    void pescaCarte(int numero) {
        // permette di pescare un numero specifico di carte dal mazzo, se disponibili.
    }

    void giocaCarta(Carta carta) {
        // gioca una carta dalla mano.

    }

    void scartaCarta(Carta carta) {
        // scarta una carta.

    }

    void prelevaCartaPremio(CartaPokemon pokemon) {
        // pesca una carta premio dopo aver sconfitto un Pokémon avversario.

    }

    boolean haCartePremio() {
        // verifica se l’allenatore ha ancora carte premio.
        return true;
    }

    void stampaMano() {

    }

    public ArrayList<Carta> getMano() {
        return mano;
    }

    public Mazzo getMazzo() {
        return mazzo;
    }

    public String getNome() {
        return nome;
    }

    public CartaPokemon getPokemonAttivo() {
        return pokemonAttivo;
    }

    public void setMano(ArrayList<Carta> mano) {
        this.mano = mano;
    }

    public void setMazzo(Mazzo mazzo) {
        this.mazzo = mazzo;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setPokemonAttivo(CartaPokemon pokemonAttivo) {
        this.pokemonAttivo = pokemonAttivo;
    }

}
