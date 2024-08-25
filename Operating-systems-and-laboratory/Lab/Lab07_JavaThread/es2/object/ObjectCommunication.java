package es2.object;

import java.io.*;

public class ObjectCommunication {

    public static void main(String[] args) {
		
        PipedInputStream pis = new PipedInputStream();
        try {
            PipedOutputStream pos = new PipedOutputStream(pis);
			
            FromInput fi = new FromInput(pos);
            ToOutput to = new ToOutput(pis);
            fi.start();
            to.start();
        } 
		catch (IOException e) {
			e.printStackTrace();
		}
    }

}