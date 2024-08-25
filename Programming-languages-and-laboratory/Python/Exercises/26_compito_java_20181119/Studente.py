from Partecipante import Partecipante


class Studente(Partecipante):
    def __init__(self, codice, tipo, nome, cognome, corso, universita, anno_corso):
        super().__init__(codice, tipo, nome, cognome)
        self._corso = corso
        self._universita = universita
        self._anno_corso = anno_corso

    def get_universita(self):
        return self._universita

    def __str__(self):
        return super().__str__() + "\t" + self._corso + "\t" + self._universita + "\t" + str(self._anno_corso) + "\t-\t-\t-"
