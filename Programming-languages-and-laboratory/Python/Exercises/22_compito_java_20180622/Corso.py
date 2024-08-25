class Corso:
    def __init__(self, codice, tipo, nome, nome_cognome_docente):
        self._codice = codice
        self._tipo = tipo
        self._nome = nome
        self._nome_cognome_docente = nome_cognome_docente

    def get_nome_corso(self):
        return self._nome

    def __str__(self):
        return self._nome + "\t" + str(self._codice)
