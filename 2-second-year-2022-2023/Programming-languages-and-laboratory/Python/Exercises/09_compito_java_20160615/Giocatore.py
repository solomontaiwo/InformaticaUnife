class Giocatore:
    def __init__(self, codice_squadra, cognome, eta, maglia, ruolo, titolare):
        self._codice_squadra = codice_squadra
        self._cognome = cognome
        self._eta = eta
        self._maglia = maglia
        self._ruolo = ruolo
        self._titolare = titolare
        
    def get_codice(self):
        return self._codice_squadra

    def __str__(self):
        return self._cognome + " " + str(self._eta) + " " + str(self._maglia) + " " + self._ruolo + " " + str(self._titolare)
