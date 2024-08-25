public class Dipendente {
	protected int codice;
	protected String tipo;
	protected String nomeDipendente;
	protected double costo;
	
	public Dipendente(int codice, String tipo, String nomeDipendente, double costo) {
		this.codice = codice;
		this.tipo = tipo;
		this.nomeDipendente = nomeDipendente;
		this.costo = costo;
	}
	
	public double getCosto()
	{
		return costo;
	}
		public int getCod()
	{
		return codice;
	}
	public String getNome()
	{
		return nomeDipendente;
	}
}