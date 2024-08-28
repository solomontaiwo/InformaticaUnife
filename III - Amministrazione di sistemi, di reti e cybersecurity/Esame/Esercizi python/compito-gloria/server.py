# SCHERZAVO, PRENDIAMO 30 E LODE
import socket

port = int(input("Inserisci la porta su cui il server deve ascoltare: "))

ssock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ssock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
ssock.bind(('0.0.0.0', port))
ssock.listen(socket.SOMAXCONN)
    
print(f"Server in ascolto sulla porta {port}")

while True:
    client, addr = ssock.accept()
    print(f"Connesso {addr}")
        
    username = client.recv(1024).decode().rstrip()
    shell = "Utente non trovato."

    if username:
        with open('/etc/passwd', 'r') as f:
            lines = f.readlines()
            for line in lines:
                parts = line.split(':')
                if parts[0] == username:
                    shell = parts[-1].strip()
                    break
        
    client.sendall(shell.encode())
    client.close()
