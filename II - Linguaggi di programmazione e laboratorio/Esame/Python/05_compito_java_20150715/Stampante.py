from Prodotto import Prodotto


class Stampante(Prodotto):
    def __init__(self, tipo, codice, modello, produttore, giorno, mese, anno, prezzo, peso):
        super().__init__(tipo, codice, modello, produttore, giorno, mese, anno, prezzo)
        self._peso = peso

    def __str__(self):
        return "Stampante\t" + super().__str__() + "\t-\t" + str(self._peso)
