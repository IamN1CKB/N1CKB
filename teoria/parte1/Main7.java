package programmazione_ad_oggetti.teoria.parte1;

public class Main7 {
    public static void main(String[] args) {
        /*
         * in questa lezione vedremo cosa sono i metodi, analoghi alle funzioni del
         * linguaggio C
         * vengono chiamati metodi e non funzioni siccome java è un linguaggio orientato
         * agli oggetti,
         * ossia ogni cosa che facciamo è strutturata in classe. lo capiremo meglio in
         * futuro
         */
        cucinare("carne"); // metodo che non ritorna niente
        int x = somma(2, 3);
        System.out.println(x);

        // possiamo fare anche overload methods, ossia metodi con lo stesso nome ma con
        // una firma diversa,
        // cioè con parametri diversi.
        float y = somma(3.4f, 3.1f); // in questo caso usiamo somma(float a, float b)
        System.out.println(y);
        float z = somma(8f, 7f, 7f); // in questo caso usiamo somma(float a, float b, float c)
        System.out.println(z);

    }

    static void cucinare(String cibo) { // static vedremo che significa
        System.out.println("sto cucinando " + cibo);
    }

    static int somma(int a, int b) {
        return a + b;
    }

    static float somma(float a, float b) {
        return a + b;
    }

    static float somma(float a, float b, float c) {
        return a + b + c;
    }

}