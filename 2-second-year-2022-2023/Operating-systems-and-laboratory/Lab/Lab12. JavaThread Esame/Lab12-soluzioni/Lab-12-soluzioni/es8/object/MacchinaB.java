package es8.object;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.PipedInputStream;
import java.util.concurrent.atomic.AtomicBoolean;

public class MacchinaB implements Runnable {

    final private AtomicBoolean isRunning = new AtomicBoolean(false);
    private PipedInputStream pis = null;
    private int lavoratiFiniti = 0;

    public MacchinaB(PipedInputStream pis) {
        this.pis = pis;
    }
	
    public void stop() {
        isRunning.set(false);
		// Thread.currentThread().interrupt();
    }
    
    public void run() {
        isRunning.set(true);
        ObjectInputStream ois = null;

        try {
            ois = new ObjectInputStream(pis);
        } catch (IOException e2) {
            e2.printStackTrace();
        }
        
        while (isRunning.get()) {
            Message msg = null;
            try {
                msg = (Message)ois.readObject();
            } catch (ClassNotFoundException | IOException e1) {
                System.err.println("Error in reading from ObjectInputStream");
                e1.printStackTrace();
            }

            System.out.println("Arrivato prodotto grezzo: " + msg.getMessage());
            //System.out.println("Inizio lavorazione prodotto finale");
            try {
                Thread.sleep(200);
            } catch(InterruptedException e) {
                e.printStackTrace();
            }
            lavoratiFiniti++;
            System.out.println("Fine lavorazione prodotto finale, lavorati finiti: " + lavoratiFiniti);
        }

    }

}