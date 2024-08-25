# client 
import socket
import sys

addr = input('Inserire indirizzo: ')
PORTA = 45000

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
try:
    sock.connect((addr, PORTA))
except:
    print("Impossibile connettersi all'endpoint specificato!")
    sys.stderr.write('Errore, termino il programma!')
    exit(1)

# invio al server la stringa 'lista processi'
cmd = 'lista processi'
sock.send(cmd.encode())
# leggere la risposta
buff = sock.recv(1024)
while len(buff) > 0:
    # stampo a video
    sys.stdout.write(buff.decode())
    # provo a leggere ancora
    # dalla socket
    buff = sock.recv(1024)
