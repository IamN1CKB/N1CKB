package programmazione_ad_oggetti.teoria.parte3;

public class Pesce implements Preda, Predatore {
    @Override
    public void caccia() {
        System.out.println("il pesce grosso caccia quelli più piccoli");

    }

    @Override
    public void scappa() {

        System.out.println("il pesce piccolo scappa da quelli più grossi");

    }
}
