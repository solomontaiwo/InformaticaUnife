import java.io.*;
import java.util.concurrent.atomic.AtomicBoolean;

public class InputUtente implements Runnable {
    private PipedOutputStream pos = null;
    final private AtomicBoolean isRunning = new AtomicBoolean(false);

    public InputUtente(PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run() {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(pos));
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));

        while (isRunning.get()) {
            try {
                String line = stdin.readLine();
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