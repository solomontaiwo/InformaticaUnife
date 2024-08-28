

public  class Servizio {
	
	protected Dipendente dip;
	protected double ore;	
	
	public Servizio(Dipendente dip, double ore){
        this.dip=dip;
		this.ore = ore;
	}
	public double getValore()
	{
		return ore*dip.getCosto();
	}
}