class Noleggio:
    def __init__(self, codice_veicolo, giorni):
        self._codice_veicolo = codice_veicolo
        self._giorni = giorni

    def __str__(self):
        return "(" + str(self._codice_veicolo) + ", " + str(self._giorni) + ")"
