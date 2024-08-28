Ho inserito due diverse versioni di Server con protocollo length-prefixed data
e riuso della socket per service molteplici richieste (consecutive) dallo
stesso Client. La versione server-concurrent-lpd-connreuse-tmpfile.c sfrutta un
file temporaneo per salvare il contenuto della risposta prima di calcolarne la
dimensione. La versione server-concurrent-lpd-connreuse-buffer.c invece usa un
buffer di memoria di 64KiB.

Ho messo nell'archivio anche il file superautomatiche.txt come esempio di file
da usare per provare il codice.
