from Articolo import Articolo


class GiaccaAVento(Articolo):
    def __init__(self, codice, tipo, marca, taglia, modello, costo, tasche, sconto):
        super().__init__(codice, tipo, marca, taglia, modello, costo, sconto)
        self._tasche = tasche

    def __str__(self):
        return super().__str__() + "\t" + str(self._tasche) + "\t-\t" + str(self._costo) + "\t" + str(self._sconto)
