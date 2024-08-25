from Prodotto import Prodotto


class Libro(Prodotto):
    def __init__(self, tipo, codice, titolo, autore, prezzo, isbn):
        super().__init__(tipo, codice, titolo, autore, prezzo)
        self._isbn = isbn

    def __str__(self):
        return super().__str__() + "\t" + self._isbn + "\t-"
    