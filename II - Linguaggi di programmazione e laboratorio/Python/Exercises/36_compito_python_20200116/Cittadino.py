from Supermercato import Supermercato


class Cittadino(Supermercato):
    def __init__(self, codice, tipo, indirizzo, apertura, chiusura, superficie, addetti):
        super().__init__(codice, tipo, indirizzo, superficie, addetti)
        self._apertura = apertura
        self._chiusura = chiusura

    def __str__(self):
        return str(self._codice) + "\t" + self._tipo + "\t" + self._indirizzo + "\t" + str(self._apertura) + "\t" +\
               str(self._chiusura) + "\t" + str(self._superficie) + "\t" + str(self._addetti) + "\t-"
    