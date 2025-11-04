package programmazione_ad_oggetti.esercizi.es_vari;

import javax.swing.JOptionPane;

public class es1 {
    public static void main(String[] args) {

        System.out.println("Hello World");
        String nome;
        nome = JOptionPane.showInputDialog("inserisci il tuo nome:");

        System.out.println("Hello " + nome);

        System.exit(0);
    }
}