public class Ricerca extends Progetto {
    private int partner;
    private String arg;

    public Ricerca(int cod, String t, String c, String o, String a, int p, double i) {
        super(cod, t, c, o, i);
        this.partner = p;
        this.arg = a;
    }

    public String toString() {
        return "ricerca\t" + super.toString() + arg + "\t" + partner + "\t" + importo * 1000;
    }
}