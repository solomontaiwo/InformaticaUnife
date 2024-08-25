class Socio:
    def __init__(self, codice_socio, nome_cognome, eta, categoria):
        self._codice_socio = codice_socio
        self._nome_cognome = nome_cognome
        self._eta = eta
        self._categoria = categoria
        self._prenotazioni = []

    def add_prenotazione(self, pren):
        self._prenotazioni.append(pren)

    def __str__(self):
        return str(self._codice_socio) + "\t" + self._nome_cognome + "\t" + str(self._eta) + "\t" +\
               str(self._categoria) + str([str(pren) for pren in self._prenotazioni])
