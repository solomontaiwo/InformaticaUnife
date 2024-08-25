package es7;

public class Produzione {
	
    private int prodotti;

    public Produzione() {
        prodotti = 0;
    }

    public synchronized void incrementa() {
        int temp = prodotti;
        Simulate.HWInterrupt();
        temp++;
        prodotti = temp;
    }

    public synchronized void stampaProduzione() {
        System.out.println("Valore produzione: " + prodotti);
    }
        
}