from noleggio import Noleggio

class Cliente:

    nome_cognome: str
    noleggi: list

    def __init__(self, nome_cognome: str, noleggi: list = None):
        self.nome_cognome = nome_cognome
        if noleggi is None:
            self.noleggi = []
        else:
            self.noleggi = noleggi 

    def add_noleggio(self, noleggio: Noleggio):
        self.noleggi.append(noleggio)

    def costo_noleggio_maggiore(self) -> float:
        max = 0
        result = 0
        for noleggio in self.noleggi:
            if noleggio.costo_giornaliero > max:
                max = noleggio.costo_giornaliero
                result = noleggio.costo_giornaliero * noleggio.numero_giorni

        return result

    
    def __str__(self):
        return self.nome_cognome + ", " + str(self.costo_noleggio_maggiore()) + ", " + str(len(self.noleggi))
