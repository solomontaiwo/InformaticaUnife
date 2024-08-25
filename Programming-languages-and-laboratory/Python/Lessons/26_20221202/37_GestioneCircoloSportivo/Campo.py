class Campo:
    def __init__(self, codice, sport, nome, larghezza, lunghezza):
        self._codice = codice
        self._sport = sport
        self._nome = nome
        self._larghezza = larghezza
        self._lunghezza = lunghezza

    def get_codice(self):
        return self._codice

    def __str__(self):
        return self._sport + "\t" + self._nome + "\t" + str(self._codice) + "\t" + str(self._larghezza) + "\t" + str(self._lunghezza)
