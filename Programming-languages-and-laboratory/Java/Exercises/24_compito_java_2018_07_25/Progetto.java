import java.io.*;
import java.util.*;

public abstract class Progetto {
    protected int codice;
    protected String titolo, coord, org;
    protected double importo;

    public Progetto(int cod, String t, String c, String o, double i) {
        codice = cod;
        titolo = t;
        coord = c;
        org = o;
        importo = i;
    }

    public String getTitolo() {
        return titolo;
    }

    public int getCod() {
        return codice;
    }

    public String toString() {
        return titolo + "\t" + codice + "\t" + coord + "\t" + org + "\t";
    }
}