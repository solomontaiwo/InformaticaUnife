class Libro:
    def __init__(self, titolo, autori, prezzo):
        self._titolo = titolo
        self._autori = autori
        self._prezzo = prezzo
        self._copie_vendute = 1

    def aggiorna_numero_copie(self):
        self._copie_vendute += 1

    def get_titolo(self):
        return self._titolo

    def __str__(self):
        return self._titolo + " " + str(self._copie_vendute)
