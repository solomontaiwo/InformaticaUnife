class Socio:
    def __init__(self, codice, nome_cognome, eta, categoria):
        self._codice = codice
        self._nome_cognome = nome_cognome
        self._eta = eta
        self._categoria = categoria
        self._prenotazioni = []

    def add_prenotazione(self, prenotazione):
        self._prenotazioni.append(prenotazione)

    def __str__(self):
        return str(self._codice) + "\t" + self._nome_cognome + "\t" + str(self._eta) + "\t" + str(self._categoria) + "\t" + str([str(pren) for pren in self._prenotazioni])


class Prenotazione:
    def __init__(self, codice, ora_inizio):
        self._codice = codice
        self._ora_inizio = ora_inizio

    def __str__(self):
        return "(" + str(self._codice) + ", " + str(self._ora_inizio) + ")"

