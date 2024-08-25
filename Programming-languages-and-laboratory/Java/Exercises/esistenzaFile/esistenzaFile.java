import java.io.File;

public class esistenzaFile {
    public static void main(String args[]) {
        File file = new File("testo.txt");
        if (file.exists()) {
            System.out.println("Il file " + file + " esiste!");
        } else {
            System.out.println("Il file " + file + " non esiste :(");
        }
    }
}