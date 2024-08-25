

public class Pallamano extends Squadra {

    private double reti;

    public Pallamano(int codice, String sport, String nome, int vinte, int perse, double reti) {
        super(codice, sport, nome, vinte, perse);
        this.reti = reti;
    }

    public String toString() {
        return nome + "\t" + codice + "\t" + vinte + "\t" + perse + "\t-\t-\t" + reti + "\t" + sport;
    }
}
