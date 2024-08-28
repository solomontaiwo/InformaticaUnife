import java.util.*;

public class Filiale {

    protected int codice;
    protected String nome, indirizzo;
    protected List<Cliente> clientiAttuali;
    protected List<Cliente> clientiPassati;

    public Filiale(int c, String n, String i) {
        codice = c;
        nome = n;
        indirizzo = i;
        clientiAttuali = new LinkedList<Cliente>();
        clientiPassati = new LinkedList<Cliente>();
    }

    public void addClAtt(Cliente c) {
        clientiAttuali.add(c);
    }

    public void addClPass(Cliente c) {
        clientiPassati.add(c);
    }

    public int nClAtt() {
        return clientiAttuali.size();
    }

    public int nClPass() {
        return clientiPassati.size();
    }

    public int getCodice() {
        return codice;
    }

    public String getNome() {
        return nome;
    }

    public String toString() {
        int na = nClAtt();
        int nt = na + nClPass();
        return nome + "\t" + na + "\t" + nt;
    }
}