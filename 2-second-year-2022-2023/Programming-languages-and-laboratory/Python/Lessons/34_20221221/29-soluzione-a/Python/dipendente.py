class Dipendente:
    codice: int
    tipo: str
    nome: str
    costo_orario: float # Python non ha il tipo double

    servizi: list

    def __init__(self, codice: int, tipo: str, nome: str, costo_orario: float, servizi: list = None):
        self.codice = codice
        self.tipo = tipo
        self.nome = nome
        self.costo_orario = costo_orario

        if servizi is None:
            self.servizi = []
        else:
            self.servizi = servizi

    def add_servizio(self, servizio):
        self.servizi.append(servizio)

    def __str__(self):
        tipo = self.tipo
        if self.tipo == "nutrizionista":
            tipo = "nutri"
        return self.nome + ", " + str(self.codice) + ", " + tipo