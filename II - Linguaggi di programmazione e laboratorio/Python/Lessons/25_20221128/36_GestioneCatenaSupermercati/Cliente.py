class Cliente:
    def __init__(self, nome, cognome):
        self._nome = nome
        self._cognome = cognome
        self._visite = []

    def add_visita(self, visita):
        self._visite.append(visita)

    def spesa_tot(self):
        tot = 0
        for v in self._visite:
            tot = tot + v.get_importo()
        return tot

    def __str__(self):
        return self._cognome + "\t" + self._nome + "\t" + str(self.spesa_tot())


class Visita:
    def __init__(self, codice, importo):
        self._codice = codice
        self._importo = importo

    def get_importo(self):
        return self._importo
