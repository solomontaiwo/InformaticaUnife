import java.util.*;

public class Squadra {
    protected String nome;
    protected int codice;
    protected String sport;
    protected int vinte;
    protected int perse;
    protected List<Giocatore> giocatori;

    public Squadra(String nome, int codice, String sport, int vinte, int perse) {
        this.nome = nome;
        this.codice = codice;
        this.sport = sport;
        this.vinte = vinte;
        this.perse = perse;
        giocatori = new LinkedList<Giocatore>();
    }

    public void addGiocatore(Giocatore g) {
        giocatori.add(g);
    }

    public int nGiocatori() {
        return giocatori.size();
    }

    public int getCodice() {
        return codice;
    }

    public List<Giocatore> getGiocatori() {
        return giocatori;
    }

    public String getNome() {
        return nome;
    }

    public String toString() {
        return nome + "\t" + codice + "\t" + vinte + "\t" + perse + "\t";
    }
}