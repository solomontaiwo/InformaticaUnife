package es2.stream;

import java.io.*;

import es2.stream.FromInput;
import es2.stream.ToOutput;

public class StreamCommunication {
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