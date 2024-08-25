import java.util.*;

public class Auto extends Veicolo {

    private int cilindrata;
    private double bagagliaio;

    public Auto(int codice, String targa, String modello,
                String marca, double costo, int cilindrata, double bagagliaio) {
        super(codice, targa, modello,
                marca, costo);
        this.cilindrata = cilindrata;
        this.bagagliaio = bagagliaio;
    }

    public String toString() {
        return "automobile\t" + super.toString() + cilindrata + "\t" + bagagliaio + "-\t-\t-";
    }

}