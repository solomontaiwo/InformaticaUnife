class Visita:
    def __init__(self, codice_supermercato, importo_speso):
        self._codice_supermercato = codice_supermercato
        self._importo_speso = importo_speso

    def get_importo_speso(self):
        return self._importo_speso
