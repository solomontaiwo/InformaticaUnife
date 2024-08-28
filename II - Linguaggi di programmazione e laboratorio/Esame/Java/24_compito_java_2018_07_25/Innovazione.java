import java.io.*;
import java.util.*;

public class Innovazione extends Progetto {

    private int aziende;

    public Innovazione(int cod, String t, String c, String o, int a, double i) {
        super(cod, t, c, o, i);
        aziende = a;
    }

    public String toString() {
        return "innovazione\t" + super.toString() + "-\t-\t" + aziende + "\t" + importo * 1000;
    }
}