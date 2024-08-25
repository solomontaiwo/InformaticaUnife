import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PipedOutputStream;
import java.util.concurrent.atomic.AtomicBoolean;

public class RilevatoreAria extends Thread {
    private AtomicBoolean isRunning = new AtomicBoolean(false);
    private PipedOutputStream pos = null;

    public RilevatoreAria(PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run() {
        isRunning.set(true);

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(pos));

        while (isRunning.get()) {
            try {
                bw.write((int) (Math.random() * 110) + "");
                bw.newLine();
                bw.write(System.currentTimeMillis() + "");
                bw.newLine();
                bw.flush();
            } catch (IOException e) {
                e.printStackTrace();
            }

            try {
                Thread.sleep(12000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public void fermaRilevatoreAria() {
        isRunning.set(false);
    }
}