package es2.buffered;

import java.io.*;

import es2.buffered.FromInput;
import es2.buffered.ToOutput;

public class BufferedCommunication {
    public static void main(String[] args) {
        PipedInputStream pis = new PipedInputStream();
        try {
            PipedOutputStream pos = new PipedOutputStream(pis);
            FromInput fi = new FromInput(pos);
            ToOutput to = new ToOutput(pis);
            fi.start();
            to.start();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}