from Squadra import Squadra


class Basket(Squadra):
    def __init__(self, nome, codice, sport, vinte, perse, punteggio_medio):
        super().__init__(nome, codice, sport, vinte, perse)
        self._punteggio_medio = punteggio_medio

    def __str__(self):
        return super().__str__() + "\t" + str(self._punteggio_medio) + "\t-\t" + self._sport
