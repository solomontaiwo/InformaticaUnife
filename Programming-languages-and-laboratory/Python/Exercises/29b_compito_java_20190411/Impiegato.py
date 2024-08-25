class Impiegato:
    def __init__(self, codice, tipo, nome, costo):
        self._codice = codice
        self._tipo = tipo
        self._nome = nome
        self._costo = costo
        self._numero_servizi_svolti = 0

    def incrementa_numero_servizi_svolti(self):
        self._numero_servizi_svolti += 1

    def get_codice(self):
        return self._codice

    def get_numero_servizi(self):
        return self._numero_servizi_svolti

    def get_costo(self):
        return self._costo

    def get_nome(self):
        return self._nome

    def get_costo_orario(self):
        return self._costo

    def __str__(self):
        return self._nome + "\t" + str(self._codice)
