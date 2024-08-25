from Campo import Campo


class Squash(Campo):
    def __init__(self, codice, sport, nome, larghezza, lunghezza, altezza, piano, costo):
        super().__init__(codice, sport, nome, larghezza, lunghezza, costo)
        self._altezza = altezza
        self._piano = piano

    def __str__(self):
        return self._sport + "\t" + self._nome + "\t" + str(self._codice) + "\t" + str(self._larghezza) + "\t" +\
               str(self._lunghezza) + "\t-\t-\t" + "\t" + str(self._altezza) + "\t" + str(self._piano) + "\t" +\
               str(self._costo)
