import socket
import subprocess

porta = input('Inserisci la porta del servizio: ')

try:
    porta = int(porta)
except: 
    print('Errore, hai inserito una porta non valida')
    exit(1)

ssock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ssock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

ssock.bind('0.0.0.0', porta)

ssock.listen(10)

while True:
    client, addr = ssock.accept()
    print('Connected ', addr)

    utente = client.recv(256)
    sutente = utente.decode()
    print('Ricevuto: ', sutente)
    cmd = 'ps -u ' + sutente
    prc = subprocess.run(cmd.split(), stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    output = prc.stdout

    rc = client.send(output)
    while rc < len(output):
        rc += client.send(output[rc:])
    client.close()
