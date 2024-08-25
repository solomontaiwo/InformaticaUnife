class Veicolo:
    def __init__(self, codice, tipo, targa, modello, marca):
        self._codice = codice
        self._tipo = tipo
        self._targa = targa
        self._modello = modello
        self._marca = marca

    def get_codice(self):
        return self._codice

    def __str__(self):
        return self._targa + "\t" + str(self._codice) + "\t" + self._modello + "\t" + self._marca
