package es2.buffered;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PipedOutputStream;
import java.nio.charset.Charset;

public class FromInput implements Runnable {
    private Thread t = null;
    private PipedOutputStream pos = null;

    FromInput(PipedOutputStream pos) {
        this.pos = pos;
    }

    public void start() {
        t = new Thread(this);
        t.start();
    }

    @Override
    public void run() {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = null;
        try {
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(pos));
            System.out.println("FromInput - Inserire uno o più messaggi:");
            while ((line = br.readLine()) != null) {
                bw.write(line);
                bw.newLine();
                bw.flush();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}