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
            try {
                String line = br.readLine();

                if (line.equals("abcde") || line.equals("1234")) {
                    System.out.println("pericolo");
                } else {
                    System.out.println("ok");
                }
            } catch (IOException e) {
                System.err.println("Errore lettura input ScansionaInput");
                e.printStackTrace();
            }
        }
    }

    public void termina() {
        isRunning.set(false);
    }
}
