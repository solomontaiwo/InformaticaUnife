class Iscritto:
    def __init__(self, tipo, codice, indirizzo, nome_account, password):
        self._tipo = tipo
        self._codice = codice
        self._indirizzo = indirizzo
        self._nome_account = nome_account
        self._password = password
        
    def get_codice_iscritto(self):
        return self._codice

    def get_tipo(self):
        return self._tipo
