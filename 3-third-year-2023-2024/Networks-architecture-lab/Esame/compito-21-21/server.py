# codice server
import socket
import subprocess

PORTA = 45000
# creo una socket server TCP
ssock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ssock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

# bind + listen + accept
ssock.bind(('0.0.0.0',PORTA))

ssock.listen(socket.SOMAXCONN)

while True:
    client, addr = ssock.accept()
    print(f"Connected {addr}")
    msg = client.recv(128)
    # dovrebbe esserci dentro
    # "lista processi\n\r"
    msg = msg.decode().rstrip()
    if msg != 'lista processi':
        client.close()
    else:
        # vado a gestire la richiesta
        # del client
        cmd = 'ps aux' # ps -e
        prc = subprocess.run(cmd.split(), stdout=subprocess.PIPE)
        client.sendall(prc.stdout)
        client.close()


