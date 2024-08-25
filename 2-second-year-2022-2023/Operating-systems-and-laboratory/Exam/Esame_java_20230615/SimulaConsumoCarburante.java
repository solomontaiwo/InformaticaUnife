import java.io.*;
import java.util.*;
import java.util.concurrent.atomic.AtomicBoolean;

public class SimulaConsumoCarburante extends Thread {
    private AtomicBoolean isRunning = new AtomicBoolean(false);
    private PipedOutputStream pos = null;
    private int carburante = 200000;

    public SimulaConsumoCarburante(PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run() {
        isRunning.set(true);
        Random random = new Random();

        ObjectOutputStream oos = null;

        try {
            oos = new ObjectOutputStream(pos);
        } catch (IOException e) {
            System.err.println("SimulaCOnsumoCarburante--- errore ObjectOutputStream");
        }

        while (isRunning.get()) {
            int consumo = random.nextInt(25);
            carburante = carburante - consumo;

            CarburanteAttuale ca = new CarburanteAttuale(carburante, System.currentTimeMillis());

            try {
                oos.writeObject(ca);
            } catch (IOException e) {
                System.err.println("SimulaConsumoCarburante--- errore writeObject");
            }

            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.err.println("SimulaConsumoCarburante--- errore sleep");
            }
        }
    }

    public void termina() {
        isRunning.set(false);
    }
}