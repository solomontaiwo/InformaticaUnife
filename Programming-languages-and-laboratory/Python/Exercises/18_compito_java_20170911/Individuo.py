from Iscritto import Iscritto


class Individuo(Iscritto):
    def __init__(self, tipo, codice, nome_cognome, indirizzo, nome_account, password):
        super().__init__(tipo, codice, indirizzo, nome_account, password)
        self._nome_cognome = nome_cognome

    def get_nome(self):
        return self._nome_cognome

    def __str__(self):
        return str(self._codice) + "\t" + self._nome_cognome + "\t-\t-\t" + self._indirizzo + "\t" + self._nome_account + "\t" + str(len(self._password))
