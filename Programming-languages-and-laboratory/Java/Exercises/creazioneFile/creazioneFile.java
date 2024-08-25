import java.util.Formatter;

public class creazioneFile {
    public static void main(String args[]) {
        try {
            Formatter f = new Formatter("creazione.txt");
            f.format("%d %s %s", 1, "Pino", "Pinoli\n");
            f.format("%d %s %s", 2, "Marco", "Marconi");
            f.close();
        } catch (Exception e) {
            System.out.println("Impossibile creare file.");
        }
    }
}