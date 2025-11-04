package programmazione_ad_oggetti.teoria.parte3;

public class Main6 {
    public static void main(String[] args) {
        /*
         * cosa cambia tra:
         */
        String stringa1 = "nome";
        String stringa2 = new String("nome");

        // vedremo che con le comparazioni abbiamo
        System.out.println(stringa1 == stringa2); // false ❌ (non stesso oggetto)
        System.out.println(stringa1.equals(stringa2)); // true ✅ (stesso contenuto)
        System.out.println("");
        /*
         * 
         * Entrambe inizializzano una stringa con lo stesso testo, **ma il modo in cui
         * lo fanno è diverso internamente**.
         * Ecco il confronto chiaro e semplice:
         * 
         * ## 🟢 `String a = "nome";` → **Stringa letterale (internata)**
         * Questo modo è più efficiente, perché:
         * - Il valore `"nome"` viene salvato in un’area speciale della memoria chiamata
         * **string pool**.
         * - Se un’altra variabile usa `"nome"`, **riutilizza lo stesso oggetto**.
         * 
         * ## 🔵 `String b = new String("nome");` → **Nuovo oggetto in memoria**
         * 
         * Questo crea **sempre un nuovo oggetto** sulla heap, anche se `"nome"` è già
         * presente nel pool.
         * 
         * ## 🧠 Riepilogo delle differenze
         * | Inizializzazione | Usa string pool? | Nuovo oggetto ogni volta? | `==` con
         * stessa stringa letterale |
         * | `String a = "nome";` | Sì | No | `true` |
         * | `String b = new String("nome");`| per la costante | Sì | `false` |
         * | "nome" interna, ma |
         * | poi crea una copia |
         * 
         * ## ✅ Quindi, quale usare?
         * - **Preferisci sempre** `String s = "testo";` se vuoi **efficienza** e
         * **condivisione** delle stringhe.
         * - Usa `new String("testo")` **solo se hai un motivo preciso** (di solito non
         * serve).
         * 
         * 
         * 
         * 
         * In Java, confrontare due stringhe con `==` o con `.equals()` **non è la
         * stessa cosa**.
         * Ti spiego tutto in modo semplice:
         * 
         * 
         * `==` → Confronta **i riferimenti**
         * Quando usi `==` tra due oggetti (come le `String`), stai chiedendo:
         * “Questi due oggetti sono **lo stesso oggetto in memoria**?”
         */
        String a = "ciao";
        String b = "ciao";
        System.out.println(a == b); // true (a volte!)
        System.out.println("");
        /*
         * 👆 Funziona in questo caso perché le stringhe **letterali** vengono
         * **internate**: Java ottimizza
         * e riusa lo stesso oggetto in memoria. Ma...
         */
        String c = new String("ciao");
        String d = new String("ciao");
        System.out.println(c == d); // false ❌
        System.out.println("");
        /*
         * 
         * `.equals()` → Confronta **il contenuto**
         * Quando usi `.equals()`, stai chiedendo:
         * > “Queste due stringhe hanno lo **stesso testo** (stessi caratteri)?”
         */
        String e = new String("ciao");
        String f = new String("ciao");
        System.out.println(e.equals(f)); // true ✅
        System.out.println("");
        /*
         * 
         * 🧠 Riepilogo:
         * 
         * | Operatore | Confronta cosa? | Uso consigliato |
         * | `==` | Riferimenti (memoria) | Solo se vuoi sapere se sono **lo stesso
         * oggetto** |
         * | `.equals()` | Contenuto (testo) | ✅ Per confrontare **stringhe** |
         * 
         * 🔥 Esempio pratico
         */
        String s1 = "ciao";
        String s2 = new String("ciao");

        System.out.println(s1 == s2); // false ❌ (non stesso oggetto)
        System.out.println(s1.equals(s2)); // true ✅ (stesso contenuto)
        System.out.println("");
        /*
         * 
         * ## ⚠️ ATTENZIONE:
         * Mai confrontare stringhe con `==` se vuoi confrontare il **testo**. Usa
         * sempre `.equals()`.
         * E se vuoi ignorare le maiuscole/minuscole:
         */
        System.out.println(s1.equalsIgnoreCase(s2)); // true

    }
}
