from Supermercato import Supermercato


class Ipermercato(Supermercato):
    def __init__(self, codice, indirizzo, superficie, addetti, nome):
        super().__init__(codice, indirizzo, superficie, addetti)
        self._nome = nome

    def __str__(self):
        return str(self._codice) + "\tiper\t" + self._indirizzo + "\t-\t-\t" + str(self._superficie) + "\t" + str(self._addetti) + "\t" + self._nome
