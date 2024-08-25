from Supermercato import Supermercato


class Cittadino(Supermercato):
    def __init__(self, codice, indirizzo, superficie, addetti, apertura, chiusura):
        super().__init__(codice, indirizzo, superficie, addetti)
        self._apertura = apertura
        self._chiusura = chiusura

    def __str__(self):
        return str(self._codice) + "\tcittadino\t" + self._indirizzo + "\t" + str(self._apertura) + "\t" + str(self._chiusura) + "\t" + str(self._superficie) + "\t" + str(self._addetti) + "\t-"
