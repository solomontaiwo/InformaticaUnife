import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class letturaFile {
    public static void main(String args[]) {
        try {
            File prova = new File("testo.txt");
            Scanner sc = new Scanner(prova);
            while (sc.hasNext()) {
                System.out.println(sc.nextLine());
            }
            sc.close();
        } catch (FileNotFoundException e) {
            System.out.println("Error, file not found.");
        }

    }
}
