public class Libro {

private String titolo;
private String autori;
private int prezzo;

public Libro(String tit, String a, int pr){
	titolo = tit;
	autori = a;
	prezzo = pr;
}

public int getPrezzo(){
	return this.prezzo;
}

}
