from dipendente import Dipendente

class Nutrizionista(Dipendente):
    telefono: int
    medico: bool
    appuntamenti_settimanali: int

    def __init__(self, codice: int, tipo: str, nome: str, costo_orario: float, telefono: int, medico: bool, appuntamenti_settimanali: int):
        super().__init__(codice, tipo, nome, costo_orario)
        self.telefono = telefono
        self.medico = medico
        self.appuntamenti_settimanali = appuntamenti_settimanali

    def __str__(self):
        return super().__str__() + ", -, -, " + str(self.telefono) + ", " + str(self.medico) + ", " + str(self.appuntamenti_settimanali) + ", " + str(self.costo_orario)