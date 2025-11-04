package programmazione_ad_oggetti.teoria.parte3;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Main5 {
    public static void main(String[] args) {
        // gestione exception
        // scriviamo un codice che prende in input 2 numeri e li divide
        /*
         * 
         * Scanner scanner =new Scanner(System.in);
         * System.out.println("inserisci un numero");
         * float x = scanner.nextFloat();
         * 
         * System.out.println("inserisci il secondo numero");
         * float y = scanner.nextFloat();
         * 
         * float result = x/y;
         * System.out.println("risultato: " + result);
         */

        Scanner scanner = new Scanner(System.in);
        // ci può essere un eccezione, dovuta a un'immissione di un valore non numerico,
        // che interrompe il programma
        // l'eccezione sarebbe InputMismatchException
        try {
            System.out.println("inserisci un numero");
            int x = scanner.nextInt();

            System.out.println("inserisci il secondo numero");
            int y = scanner.nextInt();

            int result = x / y;
            System.out.println("risultato: " + result);
        } catch (InputMismatchException e) {
            System.err.println("inserisci un numero e non altro");
        } catch (ArithmeticException e) {
            System.err.println("non puoi dividere per zero");
        } catch (Exception e) {
            System.err.println("c'è stata l'eccezione " + e);
        } finally { // esegue una porzione di codice a prescindere da come è andata la prova
            scanner.close();
        }

        System.out.println("continua ad eseguire");
        /*
         * ## 🔥 **Blocco `finally` in Java**: Cosa fa e perché è utile?
         * 
         * Il blocco **`finally`** in Java è un'istruzione opzionale che può essere
         * usata insieme a `try-catch`.
         * Il suo scopo principale è garantire che **del codice venga eseguito sempre**,
         * indipendentemente dal fatto
         * che un'eccezione venga sollevata o meno.
         * 
         * ### 📌 **Caratteristiche principali di `finally`**
         * ✅ **Eseguito sempre** → Anche se viene lanciata un'eccezione o si usa
         * `return` dentro `try` o `catch`.
         * ✅ **Utile per il rilascio di risorse** → Ad esempio, chiudere file,
         * connessioni al database o socket di rete.
         * ✅ **Può essere usato senza `catch`** → È possibile scrivere `try-finally`
         * senza `catch`.
         * 
         * ## 🎯 **Esempio base: `finally` viene sempre eseguito**
         */

        try {
            System.out.println("Blocco try eseguito");
            int risultato = 10 / 0; // Genera un'eccezione
            System.out.println(risultato);
        } catch (ArithmeticException e) {
            System.out.println("Eccezione catturata: " + e.getMessage());
        } finally {
            System.out.println("Blocco finally eseguito!");
        }
        System.out.println("Il programma continua...");
        /*
         * 🔹 **Output:**
         * ```
         * Blocco try eseguito
         * Eccezione catturata: / by zero
         * Blocco finally eseguito!
         * Il programma continua...
         * ```
         * 📌 Anche se si verifica un'eccezione, il codice dentro `finally` viene
         * eseguito.
         * 
         * ---
         * 
         * ## 🔄 Esempio con `return` nel `try`
         * Anche se il metodo restituisce un valore prima che `finally` venga raggiunto,
         * il codice nel blocco
         * `finally` viene comunque eseguito prima che il valore venga restituito.
         */
        System.out.println(test());
        // vedi alla fine del file il metodo test

        /*
         * 🔹 **Output:**
         * ```
         * Blocco finally eseguito!
         * Blocco try
         * ```
         * 📌 **Anche se c'è un `return` nel `try`, il `finally` viene eseguito prima
         * che il valore venga restituito.**
         * 
         * 
         * ## ⚠ **Attenzione: `System.exit()` può saltare il `finally`!**
         * Se si chiama `System.exit(0);` dentro `try` o `catch`, il programma termina
         * immediatamente e il `finally` **non viene eseguito**.
         */
        try {
            System.out.println("Blocco try eseguito");
            System.exit(0); // Termina il programma
        } finally {
            System.out.println("Blocco finally eseguito!"); // Questo NON verrà stampato
        }
        /*
         * ```
         * 🔹 **Output:**
         * ```
         * Blocco try eseguito
         * ```
         * 📌 **Il `finally` viene saltato a causa di `System.exit(0)`.**
         * 
         * ---
         * 
         * ## 🚀 **Riassunto**
         * | **Caratteristica** | **Dettagli** |
         * |--------------------|-------------|
         * | **Eseguito sempre** | Anche se c'è un'eccezione o un `return` |
         * | **Usato per il rilascio delle risorse** | Chiudere file, connessioni,
         * database |
         * | **Non viene eseguito solo se** | C'è `System.exit(0)` o un crash del
         * programma |
         * | **Può essere usato senza `catch`** | Si può avere `try-finally` senza
         * `catch` |
         * 
         * 
         */
    }

    public static String test() {
        try {
            return "Blocco try"; // dovrebbe far terminare il metodo, ma esegue prima il blocco finally
        } finally {
            System.out.println("Blocco finally eseguito!");
        }
        // System.out.println("Unreachable code");
        // non possiamo inserire ulteriore codice al di fuori di try, siccome il
        // compilatore si accorge che non verrà eseguito
    }
}