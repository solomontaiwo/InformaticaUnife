import socket
import sys

addr = input('Inserisci indirizzo: ')
PORTA = 45000

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    sock.connect((addr, PORTA))
except:
    print("Impossibile connettersi all'endpoint specificato")
    sys.stderr('Errore, termino il programma')
    exit(1)

cmd = 'lista processi'
sock.send(cmd.encode())

buff = sock.recv(1024)
while len(buff) > 0:
    sys.stdout.write(buff.decode())
    buff = sock.recv(1024)