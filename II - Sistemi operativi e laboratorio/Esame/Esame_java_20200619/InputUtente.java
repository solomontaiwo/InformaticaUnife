package esame.es1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PipedOutputStream;
import java.util.concurrent.atomic.AtomicBoolean;

public class InputUtente implements Runnable {

    private PipedOutputStream pos = null;
    final private AtomicBoolean isRunning = new AtomicBoolean(false);

    public InputUtente(final PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run() {
        isRunning.set(true);

        // creo un bufferedWriter per inviare delle stringhe al thread ScansionaInput
        final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(pos));
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        while (isRunning.get()) {

            System.out.println("Inserisci una stringa:");
            try {
                String line = stdin.readLine();
                //System.out.println(Thread.currentThread() + " Letto:" + line);
                bw.write(line);
                bw.newLine();
                bw.flush();
                //System.out.println(Thread.currentThread() + " Inviata stringa a ScansionaInput");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public void stop() {
        isRunning.set(false);
    }
    
}