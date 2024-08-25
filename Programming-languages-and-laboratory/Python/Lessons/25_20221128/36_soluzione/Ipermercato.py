from Supermercato import Supermercato


class Ipermercato(Supermercato):
    def __init__(self, codice, indirizzo, superficie, addetti, centro):
        super().__init__(codice, indirizzo, superficie, addetti, "iper")
        self._centro = centro

            
    def toString(self):
        return super().toString() + "-\t-\t"+str(self._superficie) + "\t" + str(self._addetti) + "\t" + self._centro