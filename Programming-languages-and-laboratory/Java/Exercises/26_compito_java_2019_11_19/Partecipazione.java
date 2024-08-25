import java.io.*;
import java.util.*;

public class Partecipazione {

	private Partecipante part;
	private int reg;

	public Partecipazione(Partecipante part, int reg) {
		this.part = part;
		this.reg = reg;
	}

	public int getReg() {
		return reg;

	}

	public String toString() {
		return part.getCognome() + " " + reg;
	}
}