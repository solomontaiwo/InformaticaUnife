import java.io.*;
import java.util.concurrent.atomic.AtomicBoolean;

public class InputUtente implements Runnable {
    private PipedOutputStream pos = null;
    private AtomicBoolean isRunning = new AtomicBoolean(false);

    public InputUtente(PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run() {
        isRunning.set(true);

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(pos));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (isRunning.get()) {
            System.out.println("Inserisci una stringa: ");
            try {
                String line = br.readLine();
                bw.write(line);
                bw.newLine();
                bw.flush();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public void stop() {
        isRunning.set(false);
    }
}