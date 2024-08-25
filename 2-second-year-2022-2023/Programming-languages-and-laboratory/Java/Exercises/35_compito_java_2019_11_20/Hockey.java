

public class Hockey extends Squadra {

    private double gol, falli;

    public Hockey(int codice, String sport, String nome, int vinte, int perse, double gol, double falli) {
        super(codice, sport, nome, vinte, perse);
        this.gol = gol;
        this.falli = falli;
    }

    public String toString() {
        return nome + "\t" + codice + "\t" + vinte + "\t" + perse + "\t" + gol + "\t" + falli + "\t-\t" + sport;
    }
}
