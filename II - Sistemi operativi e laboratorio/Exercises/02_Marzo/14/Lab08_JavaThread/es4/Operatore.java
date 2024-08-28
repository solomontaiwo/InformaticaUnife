package es4;

public class Operatore extends Thread {
    private Magazzino mag = null;

    public Operatore(Magazzino mag) {
        this.mag = mag;
    }

    public void run() {
        boolean exist = mag.verificaOggetto("bulloni");
        if (!exist) {
            System.out.println(Thread.currentThread().getId() + ": in magazzino non esiste l'oggetto bulloni, lo creo");
            mag.aggiungiOggetto("bulloni");

            Simulate.Break();
        }

        System.out.println(Thread.currentThread().getId() + ": aggiungo 1000 pezzi di bulloni");
        mag.increaseQuantity("bulloni", 1000);

        Simulate.Break();

        System.out.println(Thread.currentThread().getId() + ": rimuovo 500 pezzi di bulloni");
        mag.increaseQuantity("bulloni", -500);
    }
}