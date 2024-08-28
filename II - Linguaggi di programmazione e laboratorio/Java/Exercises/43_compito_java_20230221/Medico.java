public class Medico extends Operatore {
    private String specialita;
    private int n_visite_mese_precedente;
    private String ambulatorio;

    public Medico(int codice, String tipo, String nome_operatore, double costo_visita, String specialita,
            int n_visite_mese_precedente, String ambulatorio) {
        super(codice, tipo, nome_operatore, costo_visita);
        this.specialita = specialita;
        this.n_visite_mese_precedente = n_visite_mese_precedente;
        this.ambulatorio = ambulatorio;
    }

    public String toString() {
        return super.toString() + "\t" + specialita + "\t" + n_visite_mese_precedente + "\t" + ambulatorio
                + "\t-\t-\t-\tmedico";
    }
}