import socket

address = input('Inserire server hostname: ')
port = input('Inserire la porta a cui collegarsi: ')

endpoint = (address, int(port))

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# client si connette al server

try: 
    sock.connect(endpoint)
except: 
    print('Impossibile connettersi all\'host')
    exit(1)

utente = input('Inserisci nome utente (sul sever): ')
sock.send(utente.encode())
# while per la lettura
buff = sock.recv(1024)
while len(buff) > 0:
    print(buff.decode(), end="")
    buff = sock.recv(1024)
sock.close()