from Giocatore import Giocatore


class Normale(Giocatore):
    def __init__(self, codice, tipo, nome_cognome, circolo, vinti, disputate):
        super().__init__(codice, tipo, nome_cognome)
        self._circolo = circolo
        self._vinti = vinti
        self._disputate = disputate

    def __str__(self):
        return super().__str__() + "\t-\t-\t-\t" + self._circolo + "\t" + str(self._vinti) + "\t" + str(
            self._disputate)
