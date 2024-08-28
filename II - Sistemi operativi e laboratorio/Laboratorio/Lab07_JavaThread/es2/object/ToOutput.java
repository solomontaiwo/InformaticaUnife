package es2.object;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.PipedInputStream;

// Questa classe legge uno stream in input
// e lo redireziona sullo stdout
public class ToOutput implements Runnable {

    private Thread t = null;
    private PipedInputStream pis = null;

    ToOutput(PipedInputStream pis) {
        this.pis = pis;
    }

    // re-define start to launch the thread
    public void start() {
        t = new Thread(this);
        t.start();
    }

    @Override
    public void run() {
        System.out.println(Thread.currentThread() + " Hello, this is ToOutput");
        ObjectInputStream ois = null;
        try {
            ois = new ObjectInputStream(pis);
            while (true) {
                Message m = (Message)ois.readObject();
                if (m == null) break; // interrompi il ciclo se non ho letto niente
                System.out.println("ToOutput: " + m.getMess());
            }
        } 
		catch (IOException | ClassNotFoundException e){
			e.printStackTrace();
		}

    }
}

