# DAI GLORIA CHE PRENDIAMO 30
import socket

addr = input('Inserisci indirizzo del server: ')
port = int(input('Inserisci la porta del server: '))

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    sock.connect((addr, port))
except Exception as e:
    print(f"Impossibile connettersi all'endpoint specificato: {e}")
    exit(1)

username = input('Inserisci il nome dell\'utente: ')
sock.send(username.encode())

response = sock.recv(1024)
print("Shell di default dell'utente:", response.decode())

sock.close()
