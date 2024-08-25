from Supermercato import Supermercato


class Iper(Supermercato):
    def __init__(self, codice, tipo, indirizzo, superficie, addetti, nome):
        super().__init__(codice, tipo, indirizzo, superficie, addetti)
        self._nome = nome

    def __str__(self):
        return str(self._codice) + "\t" + self._tipo + "\t" + self._indirizzo + "\t-\t-\t" + str(self._superficie) +\
               "\t" + str(self._addetti) + "\t" + self._nome
