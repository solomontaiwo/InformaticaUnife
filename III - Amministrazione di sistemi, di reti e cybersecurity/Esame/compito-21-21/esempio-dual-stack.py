import socket

addr = ("", 8080)  # all interfaces, port 8080

if socket.has_dualstack_ipv6():
    sock = socket.create_server(addr, family=socket.AF_INET6, dualstack_ipv6=True)
else:
    sock = socket.create_server(addr)

# quando utilizzo create_server non c'è bisogno di utilizzare bind e listen

sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

while True:
    c, a = sock.accept()
    print(a)
    # receive a message
    msg = c.recv(256)
    print(msg.decode())
    c.close()