from Squadra import Squadra


class Hockey(Squadra):
    def __init__(self, codice, sport, nome, vinte, perse, goal, falli):
        super().__init__(codice, sport, nome, vinte, perse, goal)
        self._falli = falli

    def __str__(self):
        return super().__str__() + "\t" + str(self._goal) + "\t" + str(self._falli) + "\t-\t" + self._sport
