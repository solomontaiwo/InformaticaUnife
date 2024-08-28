from Supermercato import Supermercato


class Cittadino(Supermercato):
    def __init__(self, codice, indirizzo, superficie, addetti, apertura, chiusura):
        super().__init__(codice, indirizzo, superficie, addetti, "cittadino")
        self._apertura= apertura
        self._chiusura = chiusura



    def toString(self):
        return super().toString() + str(self._apertura) + "\t" + str(self._chiusura) + "\t" + str(self._superficie)+"\t"+str(self._addetti)+"\t-"
