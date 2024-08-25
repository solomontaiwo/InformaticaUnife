class Dipendente:
    def __init__(self, codice, tipo, nome, costo_orario):
        self._codice = codice
        self._tipo = tipo
        self._nome = nome
        self._costo_orario = costo_orario
        self._servizi_svolti = 0

    def incrementa_servizi(self):
        self._servizi_svolti += 1

    def get_codice(self):
        return self._codice

    def get_servizi_svolti(self):
        return self._servizi_svolti

    def __str__(self):
        return self._nome + "\t" + str(self._codice)
