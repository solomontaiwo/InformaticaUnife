class Supermercato:
    def __init__(self, codice, tipo, indirizzo, superficie, addetti):
        self._codice = codice
        self._tipo = tipo
        self._indirizzo = indirizzo
        self._superficie = superficie
        self._addetti = addetti
        self._numero_visite = 0
        self._spese = 0

    def add_spesa(self, spesa):
        self._numero_visite += 1
        self._spese += spesa

    def spesa_media(self):
        return self._spese / self._numero_visite
