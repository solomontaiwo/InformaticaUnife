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
        // il thread deve continuare a leggere dallo standard input
        // per scrivere l'output sul PipedOutputStream
        String line = null;
        ObjectOutputStream oos = null;
        try {
            oos = new ObjectOutputStream(pos);
            System.out.println("FromInput - Inserire uno o piu' messaggi:");
            while ((line = br.readLine()) != null) {
                Message m = new Message(line);
                oos.writeObject(m);
                oos.flush();
            }
        } 
		catch (IOException e) {
			e.printStackTrace();
		}
    }
}