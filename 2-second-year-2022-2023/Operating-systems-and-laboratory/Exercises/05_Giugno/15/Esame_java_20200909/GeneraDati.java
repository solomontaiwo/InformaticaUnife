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
        } catch (IOException e) {
            e.printStackTrace();
            System.err.println("Errore ObjectOutputStream GeneraDati");
        }

        while (isRunning.get()) {
            float temp = random.nextFloat() * 25 - 5;
            int umid = random.nextInt(70) + 15;

            Misure misure = new Misure(temp, umid);
            System.out.println("GeneraDati--- Temp: " + temp + " Umidita' : " + umid);

            try {
                oos.writeObject(misure);
            } catch (IOException e) {
                e.printStackTrace();
                System.err.println("Errore writeObject GeneraDati");
            }

            try {
                Thread.sleep(2500);
            } catch (InterruptedException e) {
                System.err.println("Errore sleep GeneraDati");
            }
        }
    }

    public void finisci() {
        isRunning.set(false);
    }
}