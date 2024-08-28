from Prodotto import Prodotto


class Toner(Prodotto):
    def __init__(self, tipo, codice, modello, produttore, giorno, mese, anno, prezzo, modello_stampante):
        super().__init__(tipo, codice, modello, produttore, giorno, mese, anno, prezzo)
        self._modello_stampante = modello_stampante

    def __str__(self):
        return "Toner\t" + super().__str__() + "\t" + self._modello_stampante + "\t-"
