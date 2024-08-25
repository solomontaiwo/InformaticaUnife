class Dipendente:
    def __init__(self, codice, tipo, nome, costo_orario):
        self._codice = codice
        self._tipo = tipo
        self._nome = nome
        self._costo_orario = costo_orario
        self._numero_servizi = 0

    def get_numero_servizi(self):
        return self._numero_servizi

    def add_servizio(self):
        self._numero_servizi += 1

    def get_costo(self):
        return self._costo_orario

    def get_nome(self):
        return self._nome

    def get_codice(self):
        return self._codice

    def __str__(self):
        return self._nome
