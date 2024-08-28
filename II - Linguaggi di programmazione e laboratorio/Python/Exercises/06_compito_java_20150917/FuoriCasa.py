from Partita import Partita


class FuoriCasa(Partita):
    def __init__(self, tipo, citta, data, ora, risultato, vinta):
        super().__init__(tipo, data, ora, risultato, vinta)
        self._citta = citta

    def get_citta(self):
        return self._citta

    def stampa_partita_trovata(self):
        return self._citta + "\t" + super().__str__()

    def __str__(self):
        return "-\t" + self._citta + "\t" + super().__str__()
