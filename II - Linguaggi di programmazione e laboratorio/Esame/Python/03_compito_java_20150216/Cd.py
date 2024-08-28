from Prodotto import Prodotto


class Cd(Prodotto):
    def __init__(self, tipo, codice, titolo, autore, prezzo, durata):
        super().__init__(tipo, codice, titolo, autore, prezzo)
        self._durata = durata

    def __str__(self):
        return super().__str__() + "\t-\t" + str(self._durata)
