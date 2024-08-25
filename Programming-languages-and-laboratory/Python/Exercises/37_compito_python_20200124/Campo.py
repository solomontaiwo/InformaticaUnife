class Campo:
    def __init__(self, codice, sport, nome, larghezza, lunghezza, costo):
        self._codice = codice
        self._sport = sport
        self._nome = nome
        self._larghezza = larghezza
        self._lunghezza = lunghezza
        self._costo = costo
        self._numero_prenotazioni = 0

    def incrementa_prenotazioni(self):
        self._numero_prenotazioni += 1

    def incasso(self):
        return self._numero_prenotazioni * self._costo

    def getCodice(self):
        return self._codice
        