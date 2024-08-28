public class Partita {
    protected String data;
    protected String ora;
    protected String risultato;
    protected int vittoria;

    public Partita(String data, String ora, String risultato, int vittoria) {
        this.data = data;
        this.ora = ora;
        this.risultato = risultato;
        this.vittoria = vittoria;
    }

    public int getVinta() {
        return this.vittoria;
    }

}