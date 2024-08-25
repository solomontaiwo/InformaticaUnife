from Partecipante import Partecipante


class Regolare(Partecipante):
    def __init__(self, codice, tipo, nome, cognome, ente, dipendenti, accademico):
        super().__init__(codice, tipo, nome, cognome)
        self._ente = ente
        self._dipendenti = dipendenti
        self._accademico = accademico

    def get_ente(self):
        return self._ente

    def __str__(self):
        return super().__str__() + "\t-\t-\t-\t" + self._ente + "\t" + str(self._dipendenti) + "\t" + str(self._accademico)
        