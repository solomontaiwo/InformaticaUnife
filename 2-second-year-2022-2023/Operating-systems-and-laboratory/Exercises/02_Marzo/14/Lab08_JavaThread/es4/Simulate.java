package es4;

public class Simulate {
    public static void Break() {
        if (Math.random() < 0.5) {
            try {
                Thread.sleep(200);
            } catch (InterruptedException e) {
            }
        }
    }
}