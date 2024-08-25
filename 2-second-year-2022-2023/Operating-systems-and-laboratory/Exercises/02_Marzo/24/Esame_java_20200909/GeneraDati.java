import java.io.*;
import java.util.*;
import java.util.concurrent.atomic.AtomicBoolean;

public class GeneraDati extends Thread {
    private AtomicBoolean isRunning = new AtomicBoolean(false);
    private PipedOutputStream pos = null;

    public GeneraDati(PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run() {
        isRunning.set(true);
        Random random = new Random();

        ObjectOutputStream oos = null;
        try {
            oos = new ObjectOutputStream(pos);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-1);
        }

        while (isRunning.get()) {
            float temp = random.nextFloat() * 25 - 5;
            int umidita = random.nextInt(70) + 15;

            Misure misure = new Misure(temp, umidita);
            System.out.println("GeneraDati--- Temp: " + temp + " Umidita " + umidita);

            try {
                oos.writeObject(misure);
            } catch (IOException e) {
                e.printStackTrace();
            }

            try {
                Thread.sleep(2500);
            } catch (InterruptedException e) {
            }
        }
    }

    public void finisci() {
        isRunning.set(false);
    }
}