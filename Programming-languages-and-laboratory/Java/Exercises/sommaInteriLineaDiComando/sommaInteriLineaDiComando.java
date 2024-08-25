import java.util.*;

public class sommaInteriLineaDiComando {
    public static void main(String args[]) {
        int num = 0;
        int somma = 0, i = 0;

        Scanner console = new Scanner(System.in);

        while (i < 2) {
            System.out.print("Dammi un numero: ");
            num = console.nextInt();
            somma += num;
            i++;

        }

        console.close();

        System.out.println("La somma dei numeri inseriti e' " + somma + ".");
    }
}