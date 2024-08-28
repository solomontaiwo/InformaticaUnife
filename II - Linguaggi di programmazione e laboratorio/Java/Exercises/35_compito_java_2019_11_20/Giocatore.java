

public class Giocatore {

    protected int codiceSquadra;
    protected String cognome, nome;
    protected int eta, numeroMaglia;
    protected String ruolo;
    protected boolean titolare;

    public Giocatore(int codiceSquadra, String cognome, String nome, int eta, int numeroMaglia, String ruolo, boolean titolare) {
        this.codiceSquadra = codiceSquadra;
        this.cognome = cognome;
        this.nome = nome;
        this.eta = eta;
        this.numeroMaglia = numeroMaglia;
        this.ruolo = ruolo;
        this.titolare = titolare;
    }

    public String toString() {
        return nome + "\t" + cognome + "\t" + eta + "\t" + numeroMaglia + "\t" + ruolo + "\t" + titolare + "\t";
    }
}
