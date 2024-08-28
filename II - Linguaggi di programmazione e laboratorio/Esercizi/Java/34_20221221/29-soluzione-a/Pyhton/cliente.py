from servizio import Servizio

class Cliente:
    codice: int
    nome: str
    servizi: list[Servizio]    

    def __init__(self, codice: int, nome: str, servizi: list[Servizio] = None):
        self.codice = codice
        self.nome = nome

        if servizi is None:
            self.servizi = []
        else:
            self.servizi = servizi

    def add_servizio(self, servizio: Servizio):
        self.servizi.append(servizio)

    def costo_servizi_totale(self) -> float:
        tot = 0
        for servizio in self.servizi:
            tot = tot + servizio.get_costo()

        return tot

    def __str__(self):
        return str(self.codice) + ", " + self.nome + ", " + str(self.costo_servizi_totale())