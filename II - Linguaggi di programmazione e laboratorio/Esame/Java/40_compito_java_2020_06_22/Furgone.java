import java.util.*;

public class Furgone extends Veicolo {

    private int posti;
    private String categoria;
    private boolean carico;

    public Furgone(int codice, String targa, String modello,
                   String marca, double costo, int posti, String categoria, boolean carico) {
        super(codice, targa, modello,
                marca, costo);
        this.posti = posti;
        this.categoria = categoria;
        this.carico = carico;
    }

    public String toString() {
        return "commerciale\t" + super.toString() + "\t-\t-\t" + posti + "\t" + categoria + "\t" + carico;
    }

}