public class Visita {
    protected int codice_operatore;
    protected int n_sedute;

    public Visita(int codice_operatore, int n_sedute) {
        this.codice_operatore = codice_operatore;
        this.n_sedute = n_sedute;
    }

    public String toString() {
        return "(" + codice_operatore + ", " + n_sedute + ")";
    }
}
