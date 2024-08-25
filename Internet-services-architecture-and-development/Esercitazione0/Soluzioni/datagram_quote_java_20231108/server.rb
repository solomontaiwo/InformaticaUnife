#!/usr/bin/env ruby

require 'socket'

QUOTATIONS = [
  "Adoro i piani ben riusciti",
  "Quel tappeto dava veramente un tono all'ambiente",
  "Se ci riprovi ti stacco un braccio",
  "Questo è un colpo di genio, Leonard",
  "I fagioli comunque erano uno schifo",
]

index = 0
socket = UDPSocket.new
socket.bind(nil, ARGV[0]) # first parameter is IP address: nil works as *
loop do 
  req, sender_addr = socket.recvfrom(4096)
  puts req.inspect
  if req.chomp == "QUOTE" # chomp is to play nice w/ netcat
    resp = QUOTATIONS[ index % QUOTATIONS.length ]
    socket.send resp, 0, sender_addr[3], sender_addr[1]
    index += 1
  end
end

