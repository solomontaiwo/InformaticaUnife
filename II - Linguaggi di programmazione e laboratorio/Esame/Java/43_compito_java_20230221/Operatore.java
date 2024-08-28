public class Operatore {
    protected int codice;
    protected String tipo, nome_operatore;
    protected double costo_visita;

    public Operatore(int codice, String tipo, String nome_operatore, double costo_visita) {
        this.codice = codice;
        this.tipo = tipo;
        this.nome_operatore = nome_operatore;
        this.costo_visita = costo_visita;
    }

    public String toString() {
        return nome_operatore + "\t" + codice + "\t" + costo_visita;
    }
}