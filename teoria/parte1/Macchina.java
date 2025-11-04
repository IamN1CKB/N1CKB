package programmazione_ad_oggetti.teoria.parte1;

public class Macchina extends Veicolo {
    @Override
    void muovi() {
        System.out.println("sto accelerando");
    }

    @Override
    void frena() {
        System.out.println("sto frenando");
    }
}
