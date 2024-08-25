import sys,socket

if len(sys.argv) != 5:
    print("Uso: python3 client-lpd.py hostname porta stringa1 stringa2")
    sys.exit(1)

HOST = sys.argv[1]          # The server's hostname or IP address
PORT = int(sys.argv[2])     # The port used by the server

str_a = sys.argv[3]
str_b = sys.argv[4]

bytes_a = bytes(str_a, 'utf-8')
bytes_b = bytes(str_b, 'utf-8')

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))

    s.sendall(len(str_a).to_bytes(2, byteorder='big'))
    s.sendall(bytes_a)
    s.sendall(len(str_b).to_bytes(2, byteorder='big'))
    s.sendall(bytes_b)
    data = s.recv(1024)

    print('Received', repr(data))
