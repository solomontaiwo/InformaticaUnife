package esame.es1;

import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.PipedOutputStream;
import java.util.Random;
import java.util.concurrent.atomic.AtomicBoolean;

public class GeneraDati implements Runnable {

    private AtomicBoolean isRunning = new AtomicBoolean(false);
    private PipedOutputStream pos = null;

    public GeneraDati(PipedOutputStream pos) {
        this.pos = pos;
    }
    
    public void run() {

        Random random = new Random();
        isRunning.set(true);

        ObjectOutputStream oos = null;
        try {
            oos = new ObjectOutputStream(pos);
        } catch(IOException e) {
            System.err.println(e);
            System.exit(-1);
        }

        while (isRunning.get()) {
            // genero un valore di temperatura e uno di umidita'

            // temp da -5 a 25
            float temp = random.nextFloat() * 25 - 5;
            // humidity
            int humidity = random.nextInt(70) + 15;

            Misure misure = new Misure(temp, humidity);
            System.out.println("GeneraDati--- Temp: " + temp + " Umidita' : " + humidity);

            try {
                oos.writeObject(misure);
            } catch (IOException e) {
                e.printStackTrace();
            }

            try {
                Thread.sleep(2500);
            } catch (InterruptedException ex) {}
        }
    }

    public void finisci() {
            isRunning.set(false);
    }

}