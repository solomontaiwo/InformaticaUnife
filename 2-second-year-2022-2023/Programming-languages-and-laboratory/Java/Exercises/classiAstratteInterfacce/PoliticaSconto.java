abstract class PoliticaSconto {
    public abstract double CalcolaSconto(int numeroArticoli, double prezzoArticolo);
}

class ScontoQuantita extends PoliticaSconto {
    private int minimo;
    private double percentuale;
    private double sconto;

    public ScontoQuantita(int minimo, int percentuale) {
        this.minimo = minimo;
        this.percentuale = percentuale;
    }

    public double CalcolaSconto(int numeroArticoli, double prezzoArticolo) {
        if (numeroArticoli > this.minimo) {
            sconto = ((prezzoArticolo*numeroArticoli) * percentuale) / 100.0;
        }
        else {
            sconto = 0.0;
        }
        return sconto;
    }
   
}

class CompraNArticoliPrendiUnoGratis extends PoliticaSconto {
    private int n;
    private double sconto;
    public CompraNArticoliPrendiUnoGratis(int n) {
        this.n = n;
    }

    public double CalcolaSconto(int numeroArticoli, double prezzoArticolo) {
        sconto = ((double)numeroArticoli/n) * prezzoArticolo;
        return sconto;
    }
}