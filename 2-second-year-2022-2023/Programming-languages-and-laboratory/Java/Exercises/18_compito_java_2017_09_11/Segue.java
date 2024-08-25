import java.util.*;

public class Segue {
	protected Iscritto is;
	protected List<Iscritto> codiciFollowers;
	protected int numeroFollower;

	public Segue(Iscritto is) {
		this.is = is;
		codiciFollowers = new LinkedList<Iscritto>();
	}

	public void addFollower(Iscritto is) {
		codiciFollowers.add(is);
	}
}