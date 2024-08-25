import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.PipedOutputStream;
import java.util.Random;
import java.util.concurrent.atomic.AtomicBoolean;

public class GeneraDati implements Runnable {
    private PipedOutputStream pos = null;
    private AtomicBoolean isRunning = new AtomicBoolean(false);

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
        }

        while (isRunning.get()) {
            float temp = random.nextFloat() * 25 - 5;
            int umidita = random.nextInt(70) + 15;
            Misure m = new Misure(temp, umidita);
            System.out.println("GeneraDati--- Temp: " + temp + " Umidita': " + umidita);

            try {
                oos.writeObject(m);
                oos.flush();
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