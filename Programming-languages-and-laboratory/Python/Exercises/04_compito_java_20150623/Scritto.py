from Appello import Appello


class Scritto(Appello):
    def __init__(self, tipo, codice, docente, corso, giorno, mese, anno, ora, aula, durata):
        super().__init__(tipo, codice, docente, corso, giorno, mese, anno, ora)
        self._aula = aula
        self._durata = durata

    def __str__(self):
        return "Scritto\t" + super().__str__() + "\t" + self._aula + "\t" + str(self._durata) + "\t-"
