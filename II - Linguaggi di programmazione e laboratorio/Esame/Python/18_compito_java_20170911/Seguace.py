class Seguace:
    def __init__(self, codice_iscritto, nome_ragione_sociale):
        self._codice_iscritto = codice_iscritto
        self._nome_ragione_sociale = nome_ragione_sociale
        self._seguaci = []

    def get_codice_iscritto(self):
        return self._codice_iscritto

    def aggiungi_seguace(self, s):
        self._seguaci.append(s)
        
    def get_numero_iscritti(self):
        return len(self._seguaci)
    
    def get_nome_iscritto(self):
        return self._nome_ragione_sociale

    def __str__(self):
        return str(self._codice_iscritto) + "\t" + self._nome_ragione_sociale + "\t" + str(len(self._seguaci))
