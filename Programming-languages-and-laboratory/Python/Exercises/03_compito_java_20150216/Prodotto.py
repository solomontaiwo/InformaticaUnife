class Prodotto:
    def __init__(self, tipo, codice, titolo, autore, prezzo):
        self._tipo = tipo
        self._codice = codice
        self._titolo = titolo
        self._autore = autore
        self._prezzo = prezzo

    def __str__(self):
        return self._tipo + "\t" + str(self._codice) + "\t" + self._titolo + "\t" + self._autore + "\t" + str(self._prezzo)
