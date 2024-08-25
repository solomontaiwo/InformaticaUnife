public class DatiAzionari {
    private int valore = 0;
    private String indice = null;

    public synchronized int getValore() {
        return this.valore;
    }

    public synchronized void setValore(int valore) {
        this.valore = valore;
    }

    public synchronized String getIndice() {
        return this.indice;
    }

    public synchronized void setIndice(String indice) {
        this.indice = indice;
    }
}