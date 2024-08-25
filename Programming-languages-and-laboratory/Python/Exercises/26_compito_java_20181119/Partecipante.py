class Partecipante:
    def __init__(self, codice, tipo, nome, cognome):
        self._codice = codice
        self._tipo = tipo
        self._nome = nome
        self._cognome = cognome

    def get_codice(self):
        return self._codice

    def get_tipo(self):
        return self._tipo

    def get_cognome(self):
        return self._cognome

    def __str__(self):
        return self._tipo + "\t" + str(self._codice) + "\t" + self._nome + "\t" + self._cognome
