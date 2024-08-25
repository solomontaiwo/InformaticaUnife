class Conferenza:
    def __init__(self, nome_conferenza, luogo_conferenza):
        self._nome_conferenza = nome_conferenza
        self._luogo_conferenza = luogo_conferenza
        self._partecipazioni = []
        self._costo_totale = 0

    def add_costo(self, c):
        self._costo_totale += c

    def add_partecipazione(self, par):
        self._partecipazioni.append(par)

    def __str__(self):
        return self._nome_conferenza + "\n" + self._luogo_conferenza + "\n" + str(self._costo_totale) + " " + str(len(self._partecipazioni)) + "\n" + str([str(p) for p in self._partecipazioni])
