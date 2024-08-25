from Visita import Visita


class Cliente:
    def __init__(self, cognome, nome):
        self._cognome = cognome
        self._nome = nome
        self._visite = []
        self._totale_speso = 0

    def add_spesa(self, importo_speso):
        self._totale_speso += importo_speso

    def __str__(self):
        return self._cognome + "\t" + self._nome + "\t" + str(self._totale_speso)
