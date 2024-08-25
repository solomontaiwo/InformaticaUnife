class Servizio:
    def __init__(self, codice_impiegato, ore_servizio, nome_impiegato, costo_orario):
        self._codice_impiegato = codice_impiegato
        self._ore_servizio = ore_servizio
        self._nome_impiegato = nome_impiegato
        self._costo_orario = costo_orario

    def __str__(self):
        return self._nome_impiegato + " " + str(self._ore_servizio) + " " + str(self._costo_orario * self._ore_servizio)
