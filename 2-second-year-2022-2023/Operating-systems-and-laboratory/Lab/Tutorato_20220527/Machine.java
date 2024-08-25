package esame;

import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.PipedOutputStream;
import java.util.Random;
import java.util.concurrent.atomic.AtomicBoolean;

public class Machine extends Thread {
    PipedOutputStream pos = null;
    private AtomicBoolean isRunning = new AtomicBoolean(false);
    private int prodotti_creati = 0;

    public Machine(PipedOutputStream pos){
        this.pos = pos;
    }

    public void run(){
        isRunning.set(true);
        Random r = new Random();

        ObjectOutputStream oos  = null;

        try {
            oos = new ObjectOutputStream(pos);
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
            System.exit(-1);
        }

        while(isRunning.get()){
            float num = -1000 + r.nextFloat()*2000;

            prodotti_creati++;

            Message m = new Message(prodotti_creati, num);

            try {
                oos.writeObject(m);
            } catch (IOException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }

            try {
                Thread.sleep(750);
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }

    }

    public void termina(){
        isRunning.set(false);
    }
}
