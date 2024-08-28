import java.util.*;

public abstract class Dipendente {
	
	protected int codice;
	protected String  nome;
	protected double costo;
	protected String tipo;

	
	public Dipendente(int codice,  String nome, String tipo,  double costo){
    	this.codice=codice;
		this.nome=nome;
		this.costo=costo;
		this.tipo=tipo;
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
		return nome;
	}
	public String toString(){
		return nome+"\t"+codice+"\t"+tipo;
	}
}