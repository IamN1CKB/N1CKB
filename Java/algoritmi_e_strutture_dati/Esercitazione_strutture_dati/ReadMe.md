# Esercitazioni sulle Strutture Dati

In questa cartella sono raccolti alcuni esempi di utilizzo pratico delle strutture dati studiate durante il corso. 

⚠️ **Nota bene**: *Non si tratta di esercizi d'esame*, ma piuttosto di prove di verifica (playground) scritte per testare e controllare che le strutture dati implementate precedentemente funzionino correttamente.

## Contenuto della cartella

Di seguito l'elenco dei file di test presenti e le relative strutture dati coinvolte:

* 📄 **`EsAlbero.java`**
  Prove di funzionamento generale per la struttura dati Albero.
  
* 📄 **`EsListeConcatenate.java`**
  Test per l'utilizzo e la manipolazione delle Liste Concatenate (Singly o Doubly Linked List).

* 📄 **`EsPositionalList.java`**
  Esempi pratici per verificare il funzionamento della Positional List (lista basata sui nodi / posizioni).

* 📄 **`EsQueue.java`**
  Test sulla struttura dati Coda (Queue), verificando le operazioni con logica FIFO (First-In, First-Out).

* 📄 **`EsStack.java`**
  Test sulla struttura dati Pila (Stack), verificando le operazioni con logica LIFO (Last-In, First-Out).

* 📄 **`EsVisitBinTree.java`**
  Esercitazione dedicata al test degli algoritmi di visita applicati agli Alberi Binari (ad es. visite in pre-ordine, post-ordine, in-ordine).

## Come eseguire i test

Ogni file contiene tipicamente un metodo `main`. Puoi testare le singole strutture dati compilando ed eseguendo il file di interesse. Ad esempio:

```bash
javac EsQueue.java
java EsQueue
```