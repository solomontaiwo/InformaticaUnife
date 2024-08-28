from Veicolo import Veicolo


class Caravan(Veicolo):
    def __init__(self, codice, sport, marca, larghezza, lunghezza, potenza, posti_letto, costo_giornaliero):
        super().__init__(codice, sport, marca, lunghezza, larghezza, posti_letto, costo_giornaliero)
        self._potenza = potenza
        self._numero_giorni_noleggio = 0

    def add_giorni_noleggio(self, giorni_noleggio):
        self._numero_giorni_noleggio += giorni_noleggio

    def incasso(self):
        return self._numero_giorni_noleggio * self._costo_giornaliero

    def getCodice(self):
        return str(self._codice)

    def __str__(self):
        return self._sport + "\t" + str(self._codice) + "\t" + self._marca + "\t" + str(self._larghezza) + "\t" + str(
            self._lunghezza) + "\t" + str(self._posti_letto) + "\t-\t-\t" + str(self._potenza) + "\t" + \
               str(self._costo_giornaliero)
