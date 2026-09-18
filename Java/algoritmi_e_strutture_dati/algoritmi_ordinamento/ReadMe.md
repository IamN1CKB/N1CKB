# Algoritmi di Ordinamento

Questa cartella contiene le implementazioni in Java dei principali algoritmi di ordinamento studiati. 
Questi algoritmi sono fondamentali per manipolare e organizzare i dati in modo efficiente e rappresentano un pilastro dello studio delle strutture dati.

## Contenuto

Di seguito i file inclusi in questa directory e il loro scopo:

* 🔀 **Merge Sort** (`MergeSort.java`)
  Implementazione del classico algoritmo di ordinamento basato sul paradigma *divide et impera*. Ottimo per garantire una complessità temporale prevedibile di $O(n \log n)$.

* ⚡ **Quick Sort (In-Place)** (`QuickSortInPlace.java`)
  Versione del Quick Sort ottimizzata per l'uso della memoria spaziale. Invece di allocare nuove strutture dati durante le chiamate ricorsive, questo algoritmo effettua gli scambi (swap) direttamente all'interno dell'array o della struttura originale (*in-place*).

* 📦 **Quick Sort tramite Code** (`QuickSortQueue.java`)
  Variante del Quick Sort riadattata didatticamente per operare utilizzando esplicitamente le Code (Queue) come struttura dati d'appoggio durante la fase di partizionamento degli elementi.