usiamo memset per poter settare a uno stesso valore (ossia 0) per poter facilitare la correzione da parte dell'algoritmo del prof in modo da non avere problemi
la sintessi è:
memset(void * dest, int val, sizeof(void)*N);
    void * dest è il puntatore a qualsiasi tipo, che punta alla variabile (strutturata o non) a cui si voglia settare tutti i byte a 0
    
    int val è il valore intero a cui si vogliono settare i byte (ossia 0 nel nostro caso)
    
    sizeof(void)*N è la grandezza in byte della memoria da settare a 0 a partire dal puntatore dato prima
    nel caso di un array, il terzo parametro allora sarà sizeof(tipo_array)*dimensione_massima