from Appello import Appello


class Orale(Appello):
    def __init__(self, tipo, codice, docente, corso, giorno, mese, anno, ora, max_studenti):
        super().__init__(tipo, codice, docente, corso, giorno, mese, anno, ora)
        self._max_studenti = max_studenti

    def __str__(self):
        return "Orale\t" + super().__str__() + "\t-\t-\t" + str(self._max_studenti)
