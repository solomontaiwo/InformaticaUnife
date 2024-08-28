package esame;

import java.io.IOException;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Main {
    public static void main(String[] args) {
        PipedInputStream pis = new PipedInputStream();
        PipedOutputStream pos = null;

        try {
            pos = new PipedOutputStream(pis);
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
            System.exit(-1);
        }

        Overall overall = new Overall();

        Machine m = new Machine(pos);
        Quality q = new Quality(pis, overall);

        m.start();
        q.start();

        boolean keepGoing = true;

        while(keepGoing){
            try {
                Thread.sleep(1000);
                if(overall.getDifettosi() > overall.getCorretti()){
                    System.out.println("Difettosi " + overall.getDifettosi() + 
                    " sono più che i Corretti " + overall.getCorretti());

                    m.termina();
                    q.termina();

                    keepGoing = false;
                }

            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }

        try {
            m.join();
            q.join();
        } catch (InterruptedException e) {
            //TODO: handle exception
            e.printStackTrace();
        }
    }
}
