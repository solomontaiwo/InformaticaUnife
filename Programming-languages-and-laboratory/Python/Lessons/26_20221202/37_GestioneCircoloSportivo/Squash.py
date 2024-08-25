from Campo import Campo


class Squash(Campo):
    def __init__(self, codice, sport, nome, larghezza, lunghezza, altezza, piano, costo):
        super().__init__(codice, sport, nome, larghezza, lunghezza)
        self._altezza = altezza
        self._piano = piano
        self._costo = costo
        self._numero_prenotazioni = 0

    def incrementa_prenotazione(self):
        self._numero_prenotazioni += 1

    def get_incasso(self):
        return self._costo*self._numero_prenotazioni

    def __str__(self):
        return super().__str__() + "\t-\t-\t" + str(self._altezza) + "\t" + str(self._piano) + "\t" + str(self._costo)
