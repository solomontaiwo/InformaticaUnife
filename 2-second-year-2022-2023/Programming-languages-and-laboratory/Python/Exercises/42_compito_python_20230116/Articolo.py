class Articolo:
    def __init__(self, codice, tipo, marca, taglia, modello, costo, sconto):
        self._codice = codice
        self._tipo = tipo
        self._marca = marca
        self._taglia = taglia
        self._modello = modello
        self._costo = costo
        self._sconto = sconto

    def get_costo(self):
        return self._costo

    def __str__(self):
        return self._tipo + "\t" + str(self._codice) + "\t" + self._marca + "\t" + self._modello + "\t" + self._taglia
