
class Veicolo:

    def __init__(self, codice, marca,  modello, targa,   costo):
        self._codice = codice
        self._marca =marca
        self._modello = modello
        self._costo =costo
        self._targa =targa

    def getCosto(self):
        return self._costo

    def getTarga(self):
        return self._targa

    def __str__(self):
        return str(self._targa) + "\t" +str(self._codice) + "\t" + self._modello + "\t" + self._marca + "\t" + str(
            self._costo) + "\t"
