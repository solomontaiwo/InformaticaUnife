Si realizzi un'applicazione distribuita che permetta a un utente di leggere le
prime 5 righe di un file di testo che risiede nel filesystem del Server.

L'applicazione deve avere la seguente interfaccia:

	java RemoteHeadClient hostname porta nomefile

dove hostname è il nome dell'host dove risiede il Server, porta è il numero
di porta a cui esso è associato e nomefile è il file di cui si vogliono
leggere le prime 5 righe.

Per prima cosa, il Client deve inviare al Server il nome del file a cui
l'utente è interessato. Il Server deve quindi controllare se il file esiste o
meno. In caso affermativo, il Server deve leggere le prime 5 righe del file e
trasmetterle al Client, che si occuperà di stamparle a video. In caso
negativo, il Server deve limitarsi a chiudere la connessione con il Client
senza inviare alcun messaggio di errore.
