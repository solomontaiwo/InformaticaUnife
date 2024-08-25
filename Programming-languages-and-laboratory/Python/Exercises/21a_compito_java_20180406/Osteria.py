from Ristorante import Ristorante


class Osteria(Ristorante):
    def __init__(self, codice, tipo, nome, posti, superficie, bagno_disabili):
        super().__init__(codice, tipo, nome)
        self._posti = posti
        self._superficie = superficie
        self._bagno_disabili = bagno_disabili

    def __str__(self):
        return super().__str__() + "\t-\t-\t" + str(self._posti) + "\t" + str(self._superficie) + "\t" + str(self._bagno_disabili)
