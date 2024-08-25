package Java.esercizioFileDiTesto;

import java.io.*;

public class EsempioFile {
    public static void main(String[] args) {
        // scrittura su file
        try {
            WriteLines wr = new WriteLines(args[0]); // args[0] nome file output
        } catch (IOException ex) {
            System.out.println("Errore di I/O.");
            System.exit(1); /*
                             * Terminates the currently running Java Virtual Machine. The
                             * argument serves as a status code; by convention, a nonzero status code
                             * indicates abnormal termination.
                             */
        } catch (ArrayIndexOutOfBoundsException ex) {
            System.out.println("Errore nel passaggio degli argomenti. Specificare il nome del file.");
            System.exit(1);
        }
        // lettura da file
        try {
            ReadFile rf = new ReadFile(args[0]);
        } catch (FileNotFoundException e) {
            System.out.println("File " + args[0] + " not found.");
            System.exit(1);
        } catch (IOException e) {
            System.out.println(e);
            System.exit(1);
        }
    }// main
}
