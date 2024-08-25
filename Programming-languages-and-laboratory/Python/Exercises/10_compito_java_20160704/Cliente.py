class Cliente:
    def __init__(self, tipo, codice, codice_filiale_corrente):
        self._tipo = tipo
        self._codice = codice
        self._codice_filiale_corrente = codice_filiale_corrente
        self._codici_filiali_passate = []
        self._premio_corrente = 0.0

    def add_filiale_passata(self, p):
        self._codici_filiali_passate.append(p)

    def get_codice_filiale_corrente(self):
        return self._codice_filiale_corrente

    def add_premio_corrente(self, c):
        self._premio_corrente = c

    def get_premio_corrente(self):
        return self._premio_corrente
    
    def get_codice(self):
        return self._codice
    
    def get_tipo(self):
        return self._tipo
