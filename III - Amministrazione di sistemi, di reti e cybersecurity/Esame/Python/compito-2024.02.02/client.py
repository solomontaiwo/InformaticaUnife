# compito 2024.02.02, client
import socket # Importa il modulo socket, che fornisce l'accesso alle API di rete.
import sys # Importa il modulo sys, utilizzato per gestire errori e uscire dal programma

addr = input('Inserisci indirizzo del server: ') # Chiede all'utente di inserire l'indirizzo IP del server.
port = int(input('Inserisci la porta del server: ')) # Chiede all'utente di inserire il numero di porta del server e lo converte in un intero.

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM) # Crea un socket di tipo TCP/IP (AF_INET per IPv4 e SOCK_STREAM per il protocollo TCP).

try: # Inizia un blocco try per catturare eventuali eccezioni.
    sock.connect((addr, port)) # Tenta di connettersi al server all'indirizzo e porta specificati.
except Exception as e: # Cattura qualsiasi eccezione che si verifica durante il tentativo di connessione.
    print(f"Impossibile connettersi all'endpoint specificato: {e}") # Stampa un messaggio di errore se la connessione fallisce.
    sys.exit(1) # Termina il programma con un codice di uscita 1, indicando un errore.

cmd = 'user_list' # Definisce il comando da inviare al server.
sock.send(cmd.encode()) # Invia il comando codificato (user_list) al server.

buff = sock.recv(1024) # Riceve una risposta dal server (fino a 1024 byte).
while len(buff) > 0: # Continua a leggere dalla connessione finché ci sono dati disponibili.
    sys.stdout.write(buff.decode()) # Scrive i dati ricevuti sullo standard output (console).
    buff = sock.recv(1024) # Riceve il prossimo blocco di dati.

sock.close() # Chiude il socket, terminando la connessione con il server.
