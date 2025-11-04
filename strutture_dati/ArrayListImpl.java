package strutture_dati;

public class ArrayListImpl<E>{
    //arraylist con dimensione fissa

    private int size;
    private E data[];
    
    @SuppressWarnings ("unchecked")  //perché la conversione da Object[] a E[] crea warning
    ArrayListImpl(int capacity) {
        data = (E[]) new Object[capacity];
    }


    //metodi pubblici 
    public int size() {
        //ritorna gli elementi all'interno di un array list
        return size;
    }
    public boolean isEmpty() {
        //ritorna un boolean a seconda se l'array è vuoto 
        return size == 0;
    }
    public E get(int i ) throws IndexOutOfBoundsException {
        checkIndex(i,size);
        return data[i];
    }
    public E set(int i,E e) throws IndexOutOfBoundsException {
        checkIndex(i,size);
        E temp = data[i];
        data[i] = e;
        return temp;
    }
    public void add(int i, E e) throws IndexOutOfBoundsException,IllegalStateException {
        checkIndex(i, size+1);
        if(size == data.length) {
            throw new IllegalStateException("Array Pieno");
        }
        for(int k = size-1;k>=i;k--) {
            //spostiamo tutti gli elementi a destra di una posizione 
            data[k+1] = data[k];
        }
        data[i] = e;
        size++;
    }

    public E remove(int i) throws IndexOutOfBoundsException{
        checkIndex(i, size);
        E temp = data[i];
        for(int k = i;k<size-1;k++) {
            //spostiamo tutti gli elementi a sinistra di una posizione 
            data[k] = data[k+1];
        }
        data[size-1] = null;
        size--;
        return  temp;
    }

    protected void checkIndex(int i,int n) throws IndexOutOfBoundsException {
        if(i<0||i>=n) {
            throw new IndexOutOfBoundsException("Indice " + i + " non valido");
        }
    }
}
