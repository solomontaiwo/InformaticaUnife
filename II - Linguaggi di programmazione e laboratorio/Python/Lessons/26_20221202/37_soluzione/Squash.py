from Campo import Campo



class Squash(Campo):
    def __init__(self, codice, nome,  larghezza,  lunghezza, altezza, costo, piano):
        super().__init__(codice, nome,  larghezza,  lunghezza,costo)

        self._altezza = altezza
        self._piano = piano

            
    def __str__(self):
        return "squash\t"+super().__str__() + "-\t-\t"+str(self._altezza) + "\t" + str(self._piano) + "\t" + str(self._costo)