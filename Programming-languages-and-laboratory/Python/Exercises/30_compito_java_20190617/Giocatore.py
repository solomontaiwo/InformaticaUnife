class Giocatore:
    def __init__(self, codice_squadra, cognome, nome, titolare, eta, numero_maglia, ruolo):
        self._codice_squadra = codice_squadra
        self._cognome = cognome
        self._nome = nome
        self._titolare = titolare
        self._eta = eta
        self._numero_maglia = numero_maglia
        self._ruolo = ruolo

    def get_codice_squadra(self):
        return self._codice_squadra

    def __str__(self):
        return self._nome + "\t" + self._cognome + "\t" + str(self._eta) + "\t" + str(self._numero_maglia) + "\t" + self._ruolo
