import socket

# Chiede all'utente di inserire il numero di porta su cui il server deve ascoltare e lo converte in un intero.
port = int(input("Inserisci la porta su cui il server deve ascoltare: "))

ssock = socket.socket(socket.AF_INET, socket.SOCK_STREAM) # Crea un socket di tipo TCP/IP.
ssock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) # Imposta l'opzione del socket per riutilizzare l'indirizzo locale.
ssock.bind(('0.0.0.0', port)) # Associa il socket a tutte le interfacce di rete (0.0.0.0) sulla porta specificata.
ssock.listen(socket.SOMAXCONN) # Mette il socket in modalità di ascolto per le connessioni in ingresso, con il massimo numero di connessioni in coda definito da SOMAXCONN.

# Stampa un messaggio indicando che il server è in ascolto sulla porta specificata.    
print(f"Server in ascolto sulla porta {port}")

while True: # Inizia un ciclo infinito per gestire le connessioni in ingresso.
    client, addr = ssock.accept() # Accetta una connessione in ingresso e restituisce un nuovo socket per la comunicazione con il client e l'indirizzo del client.
    print(f"Connesso {addr}") # Stampa l'indirizzo del client connesso.
    msg = client.recv(128) # Riceve un messaggio dal client (fino a 128 byte).
    msg = msg.decode().rstrip() # Decodifica il messaggio ricevuto e rimuove eventuali spazi bianchi finali.
    if msg != 'user_list': # Controlla se il messaggio ricevuto è diverso da user_list.
        client.close() # Chiude la connessione con il client se il messaggio non è user_list.
    else:
        user_list = [] # Inizializza una lista vuota per memorizzare gli utenti.
        with open('/etc/passwd', 'r') as f: # Apre il file /etc/passwd in modalità lettura.
            lines = f.readlines() # Legge tutte le righe del file.
            for line in lines: # Itera su ogni riga del file.
                parts = line.split(':') # Divide la riga in parti usando il carattere : come delimitatore.
                username = parts[0] # Estrae il nome utente (prima parte).
                shell = parts[-1].strip() # Estrae l'ultimo campo (shell) e rimuove gli spazi bianchi.
                if '/sbin/nologin' not in shell: # Verifica che la shell non sia /sbin/nologin
                    user_list.append(username) # Aggiunge il nome utente alla lista se la shell non è /sbin/nologin.
        response = '\n'.join(user_list) # Crea una stringa con tutti i nomi utente separati da newline.
        client.sendall(response.encode()) # Invia la lista di utenti al client.
    client.close() # Chiude la connessione con il client.
