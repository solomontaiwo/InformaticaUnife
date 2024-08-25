from Campo import Campo


class Tennis(Campo):
    def __init__(self, codice, sport, nome, larghezza, lunghezza, temperatura, terreno, costo):
        super().__init__(codice, sport, nome, larghezza, lunghezza)
        self._temperatura = temperatura
        self._terreno = terreno
        self._costo = costo
        self._numero_prenotazioni = 0

    def incrementa_prenotazione(self):
        self._numero_prenotazioni += 1

    def get_incasso(self):
        return self._costo * self._numero_prenotazioni

    def __str__(self):
        return super().__str__() + "\t" + str(self._temperatura) + "\t" + self._terreno + "\t-\t-\t" + str(self._costo)
