from Corso import Corso


class Teoria(Corso):
    def __init__(self, codice, tipo, nome, nome_cognome_docente, codice_aula, ore_settimanali, ore_lezione):
        super().__init__(codice, tipo, nome, nome_cognome_docente)
        self._codice_aula = codice_aula
        self._ore_settimanali = ore_settimanali
        self._ore_lezione = ore_lezione

    def __str__(self):
        return super().__str__() + "\t" + self._nome_cognome_docente + "\t" + "teoria\t" + str(self._codice_aula) + "\t" + str(self._ore_settimanali) + "\t" + str(self._ore_lezione) + "\t-\t-\t-"
