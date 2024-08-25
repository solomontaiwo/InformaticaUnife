
import java.io.*;
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

    public double getTot() {
        double tot = 0;
        for (Noleggio n : noleggi)
            tot = tot + n.getTot();
        return tot;

    }

    public String toString() {
        return nomeCognome + " " + getTot() + " " + noleggi.size() + " " + noleggi;
    }
}