class Cliente:
    def __init__(self, codice, nome, cognome, indirizzo):
        self._codice = codice
        self._nome = nome
        self._cognome = cognome
        self._indirizzo = indirizzo
        self._noleggi = []

    def add_noleggio(self, nol):
        self._noleggi.append(nol)

    def __str__(self):
        return str(self._codice) + "\t" + self._cognome + "\t" + self._nome + "\t" + self._indirizzo + "\t" + \
               str([str(nol) for nol in self._noleggi])
