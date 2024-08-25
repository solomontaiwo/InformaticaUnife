class Operatore:
    def __init__(self, codice, tipo, nome, costo_visita):
        self._codice = codice
        self._tipo = tipo
        self._nome = nome
        self._costo_visita = costo_visita

    def __str__(self):
        return self._nome + "\t" + str(self._codice) + "\t" + str(self._costo_visita)
