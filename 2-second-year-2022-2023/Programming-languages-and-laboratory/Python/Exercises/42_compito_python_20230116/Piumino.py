from Articolo import Articolo


class Piumino(Articolo):
    def __init__(self, codice, tipo, marca, taglia, peso, modello, costo, sconto):
        super().__init__(codice, tipo, marca, taglia, modello, costo, sconto)
        self._peso = peso

    def __str__(self):
        return super().__str__() + "\t-\t" + str(self._peso) + "\t" + str(self._costo) + "\t" + str(self._sconto)
