import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PipedOutputStream;
import java.util.Random;
import java.util.concurrent.atomic.AtomicBoolean;

public class RilevatoreAria extends Thread {
    private AtomicBoolean isRunning = new AtomicBoolean(false);
    private PipedOutputStream pos = null;

    public RilevatoreAria(PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run() {
        isRunning.set(true);
        Random random = new Random();

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(pos));

        while (isRunning.get()) {
            int pollini = random.nextInt(110);
            long timestamp = System.currentTimeMillis();

            try {
                bw.write(pollini + "");
                bw.newLine();
                bw.write(timestamp + "");
                bw.newLine();
                bw.flush();
            } catch (IOException e) {
                System.err.println("Errore bw.write RilevatoreAria");
            }

            try {
                Thread.sleep(12 * 1000);
            } catch (InterruptedException e) {
                System.err.println("Errore sleep RilevatoreAria");
            }
        }
    }

    public void fermaRilevatoreAria() {
        isRunning.set(false);
    }
}