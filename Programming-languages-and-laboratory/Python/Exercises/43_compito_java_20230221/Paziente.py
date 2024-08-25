class Paziente:
    def __init__(self, codice, nome):
        self._codice = codice
        self._nome = nome
        self._visite = []
        self._visite_totali = 0

    def add_visita(self, vis):
        self._visite.append(vis)

    def incrementa_n_visite_totali(self, vt):
        self._visite_totali += vt

    def get_codice_paziente(self):
        return self._codice

    def get_nome_paziente(self):
        return self._nome

    def get_visite_totali(self):
        return self._visite_totali

    def __str__(self):
        return str(self._codice) + "\t" + self._nome + "\t" + str(len(self._visite)) + "\t" + str([str(v) for v in self._visite])
