package programmazione_ad_oggetti.teoria.parte2.Pacchetto1;

public class A {
    protected int eta = 10; // può essere usato dappertutto nello stesso pacchetto (sottoclassi incluse), ma
                            // non in altri pacchetti

    boolean vero = true; // accesso default (non consente l'accesso da sottoclassi non presenti nel
                         // pacchetto)

    private int numeroPrivato = 5; // accesso private: disponibile solo in questa classe

    // usiamo l'unico attributo private per non ricevere problemi dal compilatore
    void stampa1() {
        System.out.println(numeroPrivato);
    }

}