class Cliente:
    def __init__(self, cognome, nome):
        self._cognome = cognome
        self._nome = nome
        self._visite = []

    def addVisita(self, visita):
        self._visite.append(visita)

    def getTot(self):
        tot = 0
        for p in self._visite:
            tot = tot + p.getSpesa()
        return tot
    
    def getVisite(self):
        return self._visite

    def toString(self):
        totale = self.getTot()
        return self._cognome+"\t"+self._nome + "\t"  + str(totale)
