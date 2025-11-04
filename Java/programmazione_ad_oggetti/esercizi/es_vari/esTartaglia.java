package programmazione_ad_oggetti.esercizi.es_vari;

import java.util.Scanner;

public class esTartaglia {
    public static void main(String arg[]) {
        final class Operazioni {
            public int fattoriale(int n) {
                if (n < 0)
                    return -1;

                int fat = 1;
                for (int i = 1; i <= n; i++) {
                    fat = fat * i;
                }
                return fat;
            }
        }
        Operazioni intere = new Operazioni();
        Scanner tastiera = new Scanner(System.in);
        System.out.println("Decidi fino a che potenza stampare il triagolo di tartaglia: \b");
        final int n = tastiera.nextInt();
        System.out.println("triangolo di Tartaglia da " + n + " righe:");
        for (int i = 0; i <= n; i++) {
            System.out.print("potenza " + i + "°:\t");
            for (int j = 0; j < (n - i); j++) {
                System.out.print(" ");
            }
            for (int j = 0; j < i + 1; j++) {
                System.out.print(intere.fattoriale(i) / (intere.fattoriale(j) * intere.fattoriale(i - j)) + " ");
            }
            System.out.println(" ");
        }
        tastiera.close();
    }
}