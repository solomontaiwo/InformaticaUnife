import java.util.*;
import java.io.*;

public class Cd extends Prodotto {
    private int durata;

    public Cd(int codice, String titolo, String autori, int prezzo, int durata){
        super(codice, titolo, autori, prezzo);
        this.durata = durata;
    }
    public String toString() {
        return "cd\t" + codice + "\t" + titolo + "\t" + autori + "\t" + prezzo + "\t" +  "\t-\t" + durata;
    }
}