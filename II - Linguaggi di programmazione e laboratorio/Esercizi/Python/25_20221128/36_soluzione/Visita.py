class Visita:
    def __init__(self, supermercato, spesa):
        self._supermercato = supermercato
        self._spesa= spesa
    

    def getSpesa(self):
        return self._spesa

    def getCodice(self):
        return self._supermercato
