from Cliente import Cliente


class Residenziale(Cliente):
    def __init__(self, tipo, codice, nome_cognome, tipo_contratto, indirizzo):
        super().__init__(tipo, codice, tipo_contratto, indirizzo)
        self._nome_cognome = nome_cognome
        
    def get_nome(self):
        return self._nome_cognome

    def __str__(self):
        return super().__str__() + "\t" + self._nome_cognome + "\t-\t" + self._indirizzo + "\t" + self._tipo_contratto + "\t-"
