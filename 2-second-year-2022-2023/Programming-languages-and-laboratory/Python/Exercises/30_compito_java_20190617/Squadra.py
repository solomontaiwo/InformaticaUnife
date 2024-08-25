class Squadra:
    def __init__(self, codice, sport, nome, vinte, perse):
        self._codice = codice
        self._sport = sport
        self._nome = nome
        self._vinte = vinte
        self._perse = perse
        self._giocatori = []

    def add_giocatore(self, gioc):
        self._giocatori.append(gioc)

    def get_giocatori(self):
        return self._giocatori

    def get_nome(self):
        return self._nome

    def __str__(self):
        return self._nome + "\t" + str(self._codice) + "\t" + str(self._vinte) + "\t" + str(self._perse)
