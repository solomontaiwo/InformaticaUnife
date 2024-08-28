class Incontro:
    def __init__(self, codice_primo_giocatore, codice_secondo_giocatore, set_primo_giocatore, set_secondo_giocatore):
        self._codice_primo_giocatore = codice_primo_giocatore
        self._codice_secondo_giocatore = codice_secondo_giocatore
        self._set_primo_giocatore = set_primo_giocatore
        self._set_secondo_giocatore = set_secondo_giocatore

    def get_codice_primo_giocatore(self):
        return self._codice_primo_giocatore

    def __str__(self):
        return str(self._codice_secondo_giocatore) + ":" + str(self._set_primo_giocatore) + "-" + str(self._set_secondo_giocatore)
