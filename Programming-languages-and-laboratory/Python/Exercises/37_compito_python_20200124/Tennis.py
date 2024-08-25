from Campo import Campo


class Tennis(Campo):
    def __init__(self, codice, sport, nome, larghezza, lunghezza, temperatura, terreno, costo):
        super().__init__(codice, sport, nome, larghezza, lunghezza, costo)
        self._temperatura = temperatura
        self._terreno = terreno

    def __str__(self):
        return self._sport + "\t" + self._nome + "\t" + str(self._codice) + "\t" + str(self._larghezza) + "\t" +\
               str(self._lunghezza) + "\t" + str(self._temperatura) + "\t" + self._terreno + "\t-\t-\t" +\
               str(self._costo)
