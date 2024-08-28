from Squadra import Squadra


class Pallamano(Squadra):
    def __init__(self, codice, sport, nome, vinte, perse, goal):
        super().__init__(codice, sport, nome, vinte, perse, goal)

    def __str__(self):
        return super().__str__() + "\t-\t-\t" + str(self._goal) + "\t" + self._sport
