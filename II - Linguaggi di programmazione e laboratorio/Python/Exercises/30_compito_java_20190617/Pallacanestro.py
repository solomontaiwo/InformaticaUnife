from Squadra import Squadra


class Pallacanestro(Squadra):
    def __init__(self, codice, sport, nome, vinte, perse, falli, punti_totali):
        super().__init__(codice, sport, nome, vinte, perse)
        self._falli = falli
        self._punti_totali = punti_totali

    def __str__(self):
        return super().__str__() + "\t" + str(self._punti_totali) + "\t" + str(self._falli) + "\t-\t" + self._sport
