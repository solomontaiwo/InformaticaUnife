class Supermercato:
    def __init__(self, codice, indirizzo, superficie, addetti):
        self._codice = codice
        self._indirizzo = indirizzo
        self._superficie = superficie
        self._addetti = addetti
        self._spesa_totale = 0
        self._numero_spese = 0

    def add_spesa(self, importo):
        self._spesa_totale += importo
        self._numero_spese += 1

    def spesa_media(self):
        return self._spesa_totale/self._numero_spese
