class Socio:
    def __init__(self, codice, nome_cognome, eta, categoria):
        self._codice = codice
        self._nome_cognome = nome_cognome
        self._eta=eta
        self._categoria=categoria
        self._prenotazioni = []

    def addPrenotazione(self, pren):
        self._prenotazioni.append(pren)


    def __str__(self):
        return str(self._codice)+"\t"+self._nome_cognome + "\t"  + str(self._eta)+"\t"+str(self._categoria)+"\t"+str([str(pren) for pren in self._prenotazioni])
