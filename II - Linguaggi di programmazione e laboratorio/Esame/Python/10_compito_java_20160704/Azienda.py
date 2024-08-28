from Cliente import Cliente


class Azienda(Cliente):
    def __init__(self, tipo, codice, ragione_sociale, codice_filiale_corrente):
        super().__init__(tipo, codice, codice_filiale_corrente)
        self._ragione_sociale = ragione_sociale
        self._premio_piu_tasse = 0.0

    def get_premio_piu_tasse(self):
        return self._premio_piu_tasse

    def add_premio_piu_tasse(self, pt):
        self._premio_piu_tasse += pt
        
    def get_nome(self):
        return self._ragione_sociale

    def __str__(self):
        return self._tipo + "\t" + self.ragione_sociale + "\t" + str(self._codice)
