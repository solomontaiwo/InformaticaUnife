public class Berlina extends Auto{
    double bagagliaio;
    public Berlina(String m, String pr, double bag, int p, int cod){
        super(m, pr, p, cod);
        bagagliaio = bag;
    }

    public String toString(){
        return codice + "\t" + produttore + "\t" + modello + "\t" + bagagliaio + "\t-";
    }
}