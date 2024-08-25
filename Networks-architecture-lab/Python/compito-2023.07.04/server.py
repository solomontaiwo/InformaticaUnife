# compito 2023.07.04, server
import socket
import os
import subprocess

port = int(input("Inserisci la porta su cui il server deve ascoltare: "))

ssock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ssock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
ssock.bind(('0.0.0.0', port))
ssock.listen(socket.SOMAXCONN)
    
print(f"Server in ascolto sulla porta {port}")

while True:
    client, addr = ssock.accept()
    print(f"Connesso {addr}")
        
    directory = client.recv(1024).decode().rstrip()
        
    if os.path.isdir(directory):
        result = subprocess.run(['du', '-sh', directory], capture_output=True, text=True)
        response = result.stdout.strip()
    else:
        response = f"La directory {directory} non esiste."

    client.sendall(response.encode())
    client.close()
