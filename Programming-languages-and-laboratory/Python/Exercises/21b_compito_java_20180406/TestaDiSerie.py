from Giocatore import Giocatore


class TestaDiSerie(Giocatore):
    def __init__(self, codice, tipo, nome_cognome, ranking, eta, professionista):
        super().__init__(codice, tipo, nome_cognome)
        self._ranking = ranking
        self._eta = eta
        self._professionista = professionista

    def __str__(self):
        return super().__str__() + "\t" + str(self._ranking) + "\t" + str(self._eta) + "\t" + str(self._professionista) + "\t-\t-\t-\t"
