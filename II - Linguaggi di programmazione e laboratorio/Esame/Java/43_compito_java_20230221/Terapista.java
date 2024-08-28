public class Terapista extends Operatore {
    private String terapia, studio;
    private int n_sedute_terapia;

    public Terapista(int codice, String tipo, String nome_operatore, double costo_visita, String terapia, String studio,
            int n_sedute_terapia) {
        super(codice, tipo, nome_operatore, costo_visita);
        this.terapia = terapia;
        this.studio = studio;
        this.n_sedute_terapia = n_sedute_terapia;
    }

    public String toString() {
        return super.toString() + "\t-\t-\t-\t" + terapia + "\t" + studio + "\t" + n_sedute_terapia + "\tterapista";
    }
}