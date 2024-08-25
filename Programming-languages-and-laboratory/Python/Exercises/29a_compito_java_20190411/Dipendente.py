class Dipendente:
    def __init__(self, codice, tipo, nome, costo):
        self._codice = codice
        self._tipo = tipo
        self._nome = nome
        self._costo = costo
        self._numero_servizi = 0

    def get_costo(self):
        return self._costo

    def incrementa_numero_servizi(self):
        self._numero_servizi += 1

    def get_numero_servizi(self):
        return self._numero_servizi

    def get_nome(self):
        return self._nome

    def __str__(self):
        return self._nome + "\t" + str(self._codice)
