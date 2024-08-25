from Corso import Corso


class Laboratorio(Corso):
    def __init__(self, codice, tipo, nome, nome_cognome_docente, nome_laboratorio, nome_assistente, numero_postazioni):
        super().__init__(codice, tipo, nome, nome_cognome_docente)
        self._nome_laboratorio = nome_laboratorio
        self._nome_assistente = nome_assistente
        self._numero_postazioni = numero_postazioni

    def __str__(self):
        return super().__str__() + "\t-\t-\t-\t" + self._nome_laboratorio + "\t" + self._nome_assistente + "\t" + str(self._numero_postazioni)
