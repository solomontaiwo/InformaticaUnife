package Java.esercizioFileDiTesto;

import java.io.*;

public class ReadFile {
    public ReadFile(String filename) throws IOException {
        // stream di input
        // FileReader è uno stream di dati che permette di "collegarsi" ad un file di
        // testo in lettura //BufferedReader è uno stream di manipolazione a caratteri
        // che consente di leggere stringhe
        FileReader fr = new FileReader(filename);
        BufferedReader inFile = new BufferedReader(fr);
        System.out.println("Il testo salvato è: ");
        String linea = inFile.readLine();
        /* readLine() returns null if the end of the stream has been reached */
        while (linea != null) {
            System.out.println(linea);
            linea = inFile.readLine();
        }
        inFile.close();
    }
}