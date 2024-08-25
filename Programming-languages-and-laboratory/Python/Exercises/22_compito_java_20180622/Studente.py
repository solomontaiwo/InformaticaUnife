class Studente:
    def __init__(self, matricola, nome_cognome):
        self._matricola = matricola
        self._nome_cognome = nome_cognome
        self._libretto = []
        self._somma_voti = 0
        self._voto_max = 0
        self._nome_corso_max = ""

    def add_voto(self, v, nc):
        if v == "30L":
            self._somma_voti += 31
            self._voto_max = "30L"
            self._nome_corso_max = nc
        else:
            self._somma_voti += int(v)
            if self._voto_max != "30L":
                if int(self._voto_max) < int(v):
                    self._voto_max = v
                    self._nome_corso_max = nc

    def add_libretto(self, v):
        self._libretto.append(v)

    def get_media(self):
        return self._somma_voti / len(self._libretto)

    def get_nome_studente(self):
        return self._nome_cognome

    def get_nome_corso_max(self):
        return self._nome_corso_max

    def get_matricola(self):
        return self._matricola

    def get_voto_max(self):
        return self._voto_max

    def __str__(self):
        return self._nome_cognome + " " + str(self.get_media()) + " " + str([str(l) for l in self._libretto])
