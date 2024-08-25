public class Basket extends Squadra {
    private float punteggioMedio;

    public Basket(String nome, int codice, String sport, int vinte, int perse, float punteggioMedio) {
        super(nome, codice, sport, vinte, perse);
        this.punteggioMedio = punteggioMedio;
    }

    public String toString() {
        return super.toString() + "\t-\t" + punteggioMedio + "\t" + "basket";
    }
}