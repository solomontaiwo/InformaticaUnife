public class Noleggio {
    protected String veicolo;
    protected int giorni;
    protected double costo;

    public Noleggio(String veicolo, int giorni, double costo) {
        this.veicolo = veicolo;
        this.giorni = giorni;
        this.costo = costo;
    }

    public double getTot() {
        return giorni * costo;
    }

    public String toString() {
        return "(" + veicolo + "," + giorni + ")";
    }
}
