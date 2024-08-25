class Squadra:
    def __init__(self, codice, sport, nome, vinte, perse, goal):
        self._codice = codice
        self._sport = sport
        self._nome = nome
        self._vinte = vinte
        self._perse = perse
        self._goal = goal

    def get_nome_squadra(self):
        return self._nome
    
    def get_media(self):
        return self._vinte / (self._vinte + self._perse)

    def __str__(self):
        return self._nome + "\t" + str(self._codice) + "\t" + str(self._vinte) + "\t" + str(self._perse)
