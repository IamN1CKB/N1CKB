package programmazione_ad_oggetti.teoria.parte1;

public abstract class Veicolo {
    // nelle classi astratte non possiamo metterci un body, ma solo la dichiarazione
    /*
     * dà errore perché cerchiamo di inserire un body
     * abstract void muovi() {
     * //body
     * }
     */
    abstract void muovi();

    abstract void frena();
}
