class Veicolo:
    def __init__(self, codice, tipo, targa, modello, marca, costo_giornaliero):
        self._codice = codice
        self._tipo = tipo
        self._targa = targa
        self._modello = modello
        self._marca = marca
        self._costo_giornaliero = costo_giornaliero
        self._numero_noleggi = 0

    def incrementa_numero_noleggi(self):
        self._numero_noleggi += 1

    def get_numero_noleggi(self):
        return self._numero_noleggi

    def get_targa(self):
        return self._targa

    def get_costo(self):
        return float(self._costo_giornaliero)

    def __str__(self):
        return self._targa + "\t" + str(self._codice) + "\t" + self._modello + "\t" + self._marca + "\t" + str(self._costo_giornaliero)
