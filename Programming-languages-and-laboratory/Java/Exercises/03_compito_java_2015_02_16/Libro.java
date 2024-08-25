import java.util.*;
import java.io.*;

public class Libro extends Prodotto {
    private String isbn;

    public Libro(int codice, String titolo, String autori, int prezzo, String isbn) {
        super(codice, titolo, autori, prezzo);
        this.isbn = isbn;
    }

    public String toString() {
        return "libro\t" + codice + "\t" + titolo + "\t" + autori + "\t" + prezzo + "\t" + isbn + "\t-";
    }
}