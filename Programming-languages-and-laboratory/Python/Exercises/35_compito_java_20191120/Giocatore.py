class Giocatore:
    def __init__(self, codice, cognome, nome, eta, maglia, ruolo, titolare):
        self._codice = codice
        self._cognome = cognome
        self._nome = nome
        self._eta = eta
        self._maglia = maglia
        self._ruolo = ruolo
        self._titolare = titolare

    def get_codice(self):
        return self._codice

    def __str__(self):
        return self._nome + " " + self._cognome + "\t" + str(self._eta) + "\t" + str(self._maglia) + "\t" + self._ruolo + "\t" + str(self._titolare)
