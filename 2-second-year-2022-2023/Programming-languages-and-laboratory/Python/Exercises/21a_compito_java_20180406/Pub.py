from Ristorante import Ristorante


class Pub(Ristorante):
    def __init__(self, codice, tipo, nome, dipendenti, tavoli):
        super().__init__(codice, tipo, nome)
        self._dipendenti = dipendenti
        self._tavoli = tavoli

    def __str__(self):
        return super().__str__() + "\t" + str(self._dipendenti) + "\t" + str(self._tavoli) + "\t-\t-\t-"
