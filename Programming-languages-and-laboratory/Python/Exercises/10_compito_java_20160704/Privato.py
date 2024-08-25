from Cliente import Cliente


class Privato(Cliente):
    def __init__(self, tipo, codice, nome_cognome, codice_filiale_corrente):
        super().__init__(tipo, codice, codice_filiale_corrente)
        self._nome_cognome = nome_cognome
        
    def get_nome(self):
        return self._nome_cognome

    def __str__(self):
        return self._tipo + "\t" + self._nome_cognome + "\t" + str(self._codice)
