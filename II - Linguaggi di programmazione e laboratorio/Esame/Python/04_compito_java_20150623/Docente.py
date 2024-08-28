class Docente:
    def __init__(self, nome_docente):
        self._nome_docente = nome_docente
        self._numero_appelli = 1

    def incrementa_numero_appelli(self):
        self._numero_appelli += 1

    def get_nome_docente(self):
        return self._nome_docente

    def __str__(self):
        return "Numero totale di appelli per " + self._nome_docente + ": " + str(self._numero_appelli)
