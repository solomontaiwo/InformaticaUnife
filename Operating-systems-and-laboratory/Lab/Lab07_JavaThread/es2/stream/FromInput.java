package es2.stream;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
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
        // il thread deve continuare a leggere dallo standard input
        // per scrivere l'output sul PipedOutputStream
        String line = null;
        try {
            System.out.println("FromInput - Inserire uno o piu' messaggi:");
            while ((line = br.readLine()) != null) {
                System.out.println("From stdin: " + line);
                byte[] bytes = line.getBytes(Charset.forName("UTF-8"));
                pos.write(bytes, 0, bytes.length);
                pos.flush();
            }
        } catch (IOException e) {e.printStackTrace();}
    }
}