public class Impegno {
    protected Progetto progetto;
    protected double impegno;

    public Impegno(Progetto p, double i) {
        progetto = p;
        impegno = i;
    }

    public double getOre() {
        return impegno;
    }

    public Progetto getProg() {
        return progetto;
    }

    public String toString() {
        return "(" + progetto.getCod() + "," + impegno + ")";
    }

}