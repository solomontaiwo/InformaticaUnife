package Java.esercizioFileDiTesto;

import java.io.*;

public class WriteLines {
    public WriteLines(String filename) throws IOException {
        PrintWriter output = new PrintWriter(new FileWriter(filename));
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Inserisci il testo da salvare: ");
        String linea = input.readLine();
        while (!linea.equals("")) {
            output.println(linea);
            linea = input.readLine();
        }
        input.close();
        output.close();
    }
}