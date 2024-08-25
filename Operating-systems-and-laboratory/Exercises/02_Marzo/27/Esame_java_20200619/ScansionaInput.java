import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PipedInputStream;
import java.util.concurrent.atomic.AtomicBoolean;

public class ScansionaInput implements Runnable {
    private AtomicBoolean isRunning = new AtomicBoolean(false);
    private PipedInputStream pis = null;

    public ScansionaInput(PipedInputStream pis) {
        this.pis = pis;
    }

    public void run() {
        isRunning.set(true);
        BufferedReader br = new BufferedReader(new InputStreamReader(pis));

        while (isRunning.get()) {
            String line = null;

            try {
                line = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }

            System.out.println("InputUtente ha inviato: " + line);

            if (line.equals("abcde") || line.equals("1234")) {
                System.out.println("Pericolo");
            } else {
                System.out.println("Ok");
            }
        }
    }

    public void stop() {
        isRunning.set(false);
    }
}