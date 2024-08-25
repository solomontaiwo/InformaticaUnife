from Iscritto import Iscritto


class Azienda(Iscritto):
    def __init__(self, tipo, codice, ragione_sociale, indirizzo, nome_cognome_gestore, nome_account, password):
        super().__init__(tipo, codice, indirizzo, nome_account, password)
        self._ragione_sociale = ragione_sociale
        self._nome_cognome_gestore = nome_cognome_gestore

    def get_nome(self):
        return self._ragione_sociale

    def __str__(self):
        return str(self._codice) + "\t-\t" + self._ragione_sociale + "\t" + self._nome_cognome_gestore + "\t" + self._indirizzo + "\t" + self._nome_account + "\t" + str(len(self._password))
