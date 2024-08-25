public class Libretto {
	protected int codiceCorso;
	protected String voto;

	public Libretto(int codiceCorso, String voto) {
		this.codiceCorso = codiceCorso;
		this.voto = voto;
	}

	public int getVotoAsInt() {
		if (voto.equals("30L"))
			return 31;
		else
			return Integer.parseInt(voto);
	}

	public String getVotoAsString() {
		return voto;
	}

	public int getCorso() {
		return codiceCorso;
	}

	public String toString() {
		return "(" + codiceCorso + "," + voto + ")";
	}
}