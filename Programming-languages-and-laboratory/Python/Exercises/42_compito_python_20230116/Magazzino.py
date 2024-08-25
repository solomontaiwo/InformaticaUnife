class Magazzino:
    def __init__(self, codice_articolo, quantita):
        self._codice_articolo = codice_articolo
        self._quantita = quantita

    def __str__(self):
        return "(" + str(self._codice_articolo) + ", " + str(self._quantita) + ")"
