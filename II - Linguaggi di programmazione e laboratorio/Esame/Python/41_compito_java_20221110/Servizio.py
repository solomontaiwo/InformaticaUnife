class Servizio:
    def __init__(self, codice_dipendente, ore_servizio):
        self._codice_dipendente = codice_dipendente
        self._ore_servizio = ore_servizio

    def __str__(self):
        return str(self._codice_dipendente) + ", " + str(self._ore_servizio)
