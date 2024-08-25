from Partecipazione import Partecipazione


class Ricercatore:
    def __init__(self, nome_ricercatore, cognome_ricercatore):
        self._nome_ricercatore = nome_ricercatore
        self._cognome_ricercatore = cognome_ricercatore
        self._progetti = []
        self._impegno_totale = 0
        self._impegno_max = 0
        self._nome_impegno_max = ""

    def get_impegno_max(self):
       return self._impegno_max
    
    def get_nome_impegno_max(self):
       return self._nome_impegno_max

    def get_nome(self):
       return self._nome_ricercatore

    def get_cognome(self):
        return self._cognome_ricercatore

    def add_ore_impegno(self, oi, noi):
        self._impegno_totale += oi
        if self._impegno_max < oi:
            self._impegno_max = oi
            self._nome_impegno_max = noi

    def add_progetto(self, pr):
        self._progetti.append(pr)

    def __str__(self):
        return self._nome_ricercatore + " " + self._cognome_ricercatore + " " + str(self._impegno_totale) + " " + str(len(self._progetti)) + " " + str([str(p) for p in self._progetti])
