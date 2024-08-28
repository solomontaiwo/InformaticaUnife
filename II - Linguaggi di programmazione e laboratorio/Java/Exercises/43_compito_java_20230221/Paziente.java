import java.util.*;

public class Paziente {
    protected int codice_paziente;
    protected String nome_paziente;
    protected List<Visita> visite;
    protected int n_visite_totali;

    public Paziente(int codice_paziente, String nome_paziente) {
        this.codice_paziente = codice_paziente;
        this.nome_paziente = nome_paziente;
        visite = new LinkedList<Visita>();
        n_visite_totali = 0;
    }

    public void addVisita(Visita vis) {
        visite.add(vis);
    }

    public void incrementaNumeroVisiteTotali(int n_visite) {
        n_visite_totali += n_visite;
    }

    public int getNumeroVisiteTotali() {
        return n_visite_totali;
    }

    public String getNomePaziente() {
        return nome_paziente;
    }

    public int getCodicePaziente() {
        return codice_paziente;
    }

    public String toString() {
        // uso medoto ".size" per ricavare dalla lista "visite" il numero di operatori
        // che hanno fatto visite
        return codice_paziente + "\t" + nome_paziente + "\t" + visite.size() + "\t" + visite;
    }
}