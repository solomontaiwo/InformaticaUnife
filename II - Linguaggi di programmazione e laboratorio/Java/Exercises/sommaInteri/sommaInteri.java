import java.util.*;

public class sommaInteri {
    public static void main(String args[]){
        int num = 0;
        int somma = 0;
        int ciclo = 1;

        Scanner console = new Scanner(System.in);

        while (ciclo <= 2){
            System.out.print("Inserisci il numero " + ciclo + ": ");
            num = console.nextInt();
            somma += num;
            ciclo++;
        }

        console.close();

        System.out.println("La somma dei valori da te inseriti e' pari a " + somma + ".");
    }
}