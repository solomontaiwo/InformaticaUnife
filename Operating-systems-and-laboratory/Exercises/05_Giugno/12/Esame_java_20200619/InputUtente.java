import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PipedOutputStream;
import java.util.concurrent.atomic.AtomicBoolean;

public class InputUtente implements Runnable {
    private AtomicBoolean isRunning = new AtomicBoolean(false);
    private PipedOutputStream pos = null;

    public InputUtente(PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run() {
        isRunning.set(true);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(pos));

        while (isRunning.get()) {
            System.out.println("Inserisci una stringa: ");

            try {
                String line = br.readLine();
                bw.write(line);
                bw.newLine();
                bw.flush();
            } catch (IOException e) {
                System.err.println("Errore write in InputUtente");
                e.printStackTrace();
            }
        }
    }

    public void termina() {
        isRunning.set(false);
    }
}