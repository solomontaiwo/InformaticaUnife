from Campo import Campo


class Tennis(Campo):
    def __init__(self, codice, nome,  larghezza,  lunghezza, temperatura, costo, terreno):
        super().__init__(codice, nome,  larghezza,  lunghezza,costo)
        self._temperatura= temperatura
        self._terreno = terreno



    def __str__(self):
        return "tennis\t"+super().__str__() + str(self._temperatura) + "\t" + self._terreno + "\t-\t-\t" + str(self._costo)
