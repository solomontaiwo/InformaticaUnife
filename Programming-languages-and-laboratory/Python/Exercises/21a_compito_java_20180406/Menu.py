class Menu:
    def __init__(self, codice, descrizione_prodotto, tipo, prezzo, costo_materie_prime):
        self._codice = codice
        self._descrizione_prodotto = descrizione_prodotto
        self._tipo = tipo
        self._prezzo = prezzo
        self._costo_materie_prime = costo_materie_prime

    def __str__(self):
        return self._descrizione_prodotto + ": " + str(self._prezzo) + "-" + str(self._costo_materie_prime)
