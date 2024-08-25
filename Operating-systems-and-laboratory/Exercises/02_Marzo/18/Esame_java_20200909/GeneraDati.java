import java.io.*;
import java.util.*;
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
        } catch (IOException e) {
            System.err.println(e);
            System.exit(-1);
        }

        while (isRunning.get()) {
            float temp = random.nextFloat() * 25 - 5;
            int humidity = random.nextInt(70) + 15;

            Misure misure = new Misure(temp, humidity);

            System.out.println("GeneraDati--- Temp: " + temp + " Umidità: " + humidity);

            try {
                oos.writeObject(misure);
            } catch (IOException e) {
                e.printStackTrace();
            }

            try {
                Thread.sleep(2500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public void finisci() {
        isRunning.set(false);
    }
}