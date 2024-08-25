# compito 21-21, server
import socket
import subprocess

PORTA = 45000
ssock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ssock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

ssock.bind(('0.0.0.0', PORTA))
ssock.listen(socket.SOMAXCONN)

while True: 
    client, addr = ssock.accept()
    print(f"Connected {addr}")
    msg = client.recv(128)
    msg = msg.decode().rstrip()
    if msg != 'lista processi':
        client.close()
    else:
        cmd = 'ps aux'
        prc = subprocess.run(cmd.split(), stdout=subprocess.PIPE)
        client.sendall(prc.stdout)
        client.close()