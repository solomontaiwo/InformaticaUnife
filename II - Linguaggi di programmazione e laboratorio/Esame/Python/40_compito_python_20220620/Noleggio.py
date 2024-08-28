class Noleggio:
    def __init__(self, targa, giorni, costo):
        self._targa = targa
        self._giorni = giorni
        self._costo = costo

    def getTarga(self):
        return self._targa

    def getCosto(self):
        return self._giorni * self._costo

    def __str__(self):
        return "(" + str(self._targa) + "," + str(self._giorni) + ")"
