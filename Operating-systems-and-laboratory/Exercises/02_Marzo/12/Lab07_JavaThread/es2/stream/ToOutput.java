package es2.stream;

import java.io.IOException;
import java.io.PipedInputStream;
import java.nio.channels.Pipe;
import java.nio.charset.Charset;
import java.util.Arrays;

public class ToOutput implements Runnable {
    private Thread t = null;
    private PipedInputStream pis = null;

    ToOutput(PipedInputStream pis) {
        this.pis = pis;
    }

    public void start() {
        t = new Thread(this);
        t.start();
    }

    @Override
    public void run() {
        try {
            byte buffer[] = new byte[1024];
            int nread = 0;
            while ((nread = pis.read(buffer)) > 0) {
                byte message_buffer[] = Arrays.copyOfRange(buffer, 0, nread);
                String message = new String(message_buffer, Charset.forName("UTF-8"));
                System.out.println(message);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}