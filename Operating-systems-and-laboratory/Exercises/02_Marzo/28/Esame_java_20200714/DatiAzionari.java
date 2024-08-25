public class DatiAzionari {
    private int valore = 0;
    private String indice = null;

    public synchronized String getIndice() {
        return indice;
    }

    public synchronized void setIndice(String indice) {
        this.indice = indice;
    }

    public synchronized int getValore() {
        return valore;
    }

    public synchronized void setValore(int valore) {
        this.valore = valore;
    }
}