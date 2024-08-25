class Giocatore:
    def __init__(self, codice, tipo, nome_cognome):
        self._codice = codice
        self._tipo = tipo
        self._nome_cognome = nome_cognome
        self._incontri = []
        self._partite_vinte = 0

    def add_incontro(self, i):
        self._incontri.append(i)

    def get_nome_giocatore(self):
        return self._nome_cognome

    def add_partita_vinta(self):
        self._partite_vinte += 1

    def get_partite_vinte(self):
        return int(self._partite_vinte)

    def stampa_incontri(self):
        return self._nome_cognome + "\n" + str([str(i) for i in self._incontri])

    def __str__(self):
        return self._nome_cognome + "\t" + str(self._codice) + "\t" + self._tipo
