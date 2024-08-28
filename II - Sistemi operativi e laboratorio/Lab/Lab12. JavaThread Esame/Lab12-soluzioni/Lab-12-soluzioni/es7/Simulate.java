package es7;

import java.util.Random;

public class Simulate {
    public static void HWInterrupt() {
        if (Math.random() < 0.25) {
            try {
                Thread.sleep(200);
            } catch(InterruptedException e) {}
        }
    }
}