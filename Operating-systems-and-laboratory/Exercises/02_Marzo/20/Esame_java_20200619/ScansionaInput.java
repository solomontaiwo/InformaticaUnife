import java.io.*;
import java.util.concurrent.atomic.AtomicBoolean;

public class ScansionaInput implements Runnable {
    private PipedInputStream pis = null;
    private AtomicBoolean isRunning = new AtomicBoolean(false);

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
                System.err.println(Thread.currentThread() + "Errore lettura da BufferedReader");
            }
            System.out.println("InputUtente ha inviato: " + line);

            if (line.equals("abdce") || line.equals("1234")) {
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