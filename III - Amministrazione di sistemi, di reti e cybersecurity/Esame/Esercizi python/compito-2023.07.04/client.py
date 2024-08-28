import socket

addr = input('Inserisci indirizzo del server: ')
port = int(input('Inserisci la porta del server: '))

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    sock.connect((addr, port))
except Exception as e:
    print(f"Impossibile connettersi all'endpoint specificato: {e}")
    exit(1)

directory = input('Inserisci il nome della directory: ')
sock.send(directory.encode())

response = sock.recv(1024)
print("Dimensione della directory:", response.decode())

sock.close()
