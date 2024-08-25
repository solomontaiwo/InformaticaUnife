import java.util.*;

public class Auto extends Veicolo {
    private int cilindrata;
    private double bagagliaio;
    private String categoria;

    public Auto(int codice, String targa, String modello, String marca, double costo, int cilindrata, double bagagliaio, String categoria) {
        super(codice, targa, modello, marca, costo);
        this.cilindrata = cilindrata;
        this.bagagliaio = bagagliaio;
        this.categoria = categoria;
    }

    public String toString() {
        return "automobile\t" + super.toString() + bagagliaio + "\t" + cilindrata + "\t" + categoria + "\t-\t-\t-";
    }
}