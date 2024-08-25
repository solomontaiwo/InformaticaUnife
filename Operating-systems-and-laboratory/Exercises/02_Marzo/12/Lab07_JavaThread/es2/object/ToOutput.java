package es2.object;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.PipedInputStream;

public class ToOutput implements Runnable {
    private Thread t = null;
    private PipedInputStream pis = null;

    ToOutput(PipedInputStream pis) {
        this.pis = pis;
    }

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
                Message m = (Message) ois.readObject();
                if (m == null)
                    break;
                System.out.println("ToOutput: " + m.getMess());
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}