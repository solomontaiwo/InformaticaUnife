from Squadra import Squadra


class Pallavolo(Squadra):
    def __init__(self, nome, codice, sport, vinte, perse, numero_medio_set_vinti):
        super().__init__(nome, codice, sport, vinte, perse)
        self._numero_medio_set_vinti = numero_medio_set_vinti

    def __str__(self):
        return super().__str__() + "\t-\t" + str(self._numero_medio_set_vinti) + "\t" + self._sport
