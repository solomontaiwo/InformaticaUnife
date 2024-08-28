package es2.object;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.ObjectOutputStream;
import java.io.PipedOutputStream;

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
        ObjectOutputStream oos = null;
        try {
            oos = new ObjectOutputStream(oos);
            System.out.println("FromInput - Inserire uno o più messaggi:");
            while ((line = br.readLine()) != null) {
                Message m = new Message(line);
                oos.writeObject(m);
                oos.flush();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}