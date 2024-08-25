import socket
import sys

addr = input('Inserisci indirizzo del server: ')
port = int(input('Inserisci la porta del server: '))

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    sock.connect((addr, port))
except Exception as e:
    print(f"Impossibile connettersi all'endpoint specificato: {e}")
    sys.exit(1)

directory = input('Inserisci il percorso assoluto della directory: ')
sock.send(directory.encode())

response = sock.recv(4096)
print("Dimensione della directory e delle sue sottodirectory (fino a profondità 2): ", response.decode())

sock.close()
