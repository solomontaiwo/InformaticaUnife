import java.util.*;

public class Cliente {
    private String nomeCognome;
    private List<Noleggio> noleggi;

    public Cliente(String nomeCognome) {
        this.nomeCognome = nomeCognome;
        this.noleggi = new LinkedList<Noleggio>();
    }

    public void addNoleggio(String targa, int giorni, double costo) {
        noleggi.add(new Noleggio(targa, giorni, costo));
    }

    public double getMax() {
        double max = 1.0;
        for (Noleggio n : noleggi) {
            double costo = n.getTot();
            if (costo > max)
                max = costo;
        }
        return max;
    }

    public String toString() {
        return nomeCognome + " " + getMax() + noleggi.size();
    }
}
