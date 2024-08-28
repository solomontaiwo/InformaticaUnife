package es8.object;

import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.PipedOutputStream;
import java.util.concurrent.atomic.AtomicBoolean;

public class MacchinaA implements Runnable {
    private PipedOutputStream pos = null;

    public MacchinaA(PipedOutputStream pos) {
        this.pos = pos;
    }

    final AtomicBoolean isRunning = new AtomicBoolean(false);
	
    public void stop() {
        isRunning.set(false);
		// Thread.currentThread().interrupt();
    }
    
    public void run() {
        isRunning.set(true);
        ObjectOutputStream oos = null;
        try {
          oos = new ObjectOutputStream(pos);
        } catch(IOException e){
            e.printStackTrace();
            System.exit(-2);
        }

        while (isRunning.get()) {
            System.out.println("Inizio lavorazione prodotto");
            try {
                Thread.sleep(200);
            } catch(InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("Fine lavorazione prodotto");
            Message m = new Message("prodotto-grezzo");
            try {
                oos.writeObject(m);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
	
}