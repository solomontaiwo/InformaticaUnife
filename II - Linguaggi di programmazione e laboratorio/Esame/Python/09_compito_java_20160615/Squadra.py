class Squadra:
    def __init__(self, nome, codice, sport, vinte, perse):
        self._nome = nome
        self._codice = codice
        self._sport = sport
        self._vinte = vinte
        self._perse = perse
        self._giocatori = []

    def add_giocatore(self, g):
        self._giocatori.append(g)

    def stampa_squadra(self):
        print("La squadra " + self._nome + " ha " +
              str(len(self._giocatori)) + " giocatori.")

    def __str__(self):
        return self._nome + "\t" + str(self._codice) + "\t" + str(self._vinte) + "\t" + str(self._perse)
