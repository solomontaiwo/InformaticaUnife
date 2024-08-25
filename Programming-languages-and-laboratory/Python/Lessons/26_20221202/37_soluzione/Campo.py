


class Campo:
    def __init__(self, codice, nome,  larghezza,  lunghezza,   costo):
        self._codice = codice
        self._nome=nome
        self._larghezza = larghezza
        self._lunghezza = lunghezza
        self._costo=costo
        self._prenotazioni = 0

    def addPrenotazione(self):
    	self._prenotazioni=self._prenotazioni+1;	
    def incasso(self):
    	return self._prenotazioni*self._costo;
 
    def __str__(self):
        return self._nome+"\t"+str(self._codice) + "\t" + str(self._larghezza)+"\t"+str(self._lunghezza)+"\t"
