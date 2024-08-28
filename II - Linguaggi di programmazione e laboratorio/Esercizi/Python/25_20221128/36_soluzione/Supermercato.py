


class Supermercato:
    def __init__(self, codice, indirizzo, superficie, addetti, tipo):
        self._codice = codice
        self._indirizzo = indirizzo
        self._superficie = superficie
        self._addetti=addetti
        self._tipo = tipo

    def getTipo(self):
        return self._tipo

    def getCode(self):
        return self._codice


    def toString(self):
        return str(self._codice)+"\t"+self._tipo + "\t" + self._indirizzo+"\t"
