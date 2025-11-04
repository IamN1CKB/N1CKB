package programmazione_ad_oggetti.teoria.parte1;

public class Pizza {
    String impasto;
    String salsa;
    String formaggio;
    String extra;

    Pizza(String impasto, String salsa, String formaggio, String extra) {
        this.impasto = impasto;
        this.salsa = salsa;
        this.formaggio = formaggio;
        this.extra = extra;
        System.out.println("ingredienti: impasto " + impasto + ", " + salsa + ", " + formaggio + ", " + extra);
    }

    Pizza(String impasto, String salsa, String extra) {
        this.impasto = impasto;
        this.salsa = salsa;
        this.extra = extra;
        System.out.println("ingredienti: impasto " + impasto + ", " + salsa + ", " + extra);
    }
}
