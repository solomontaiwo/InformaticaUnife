package es4;

public class Esercizio4 {
    final static int N = 5;

    public static void main(String[] args) {
        System.out.println("Esercizio4");

        Magazzino mag = new Magazzino();
        Operatore operatori[] = new Operatore[N];

        for (int i = 0; i < N; i++) {
            operatori[i] = new Operatore(mag);
            operatori[i].start();
        }
        for (int i = 0; i < N; i++) {
            try {
                operatori[i].join();
            } catch (InterruptedException e) {
            }
        }
        System.out.println("Magazzino:");
        System.out.println(mag);
    }
}