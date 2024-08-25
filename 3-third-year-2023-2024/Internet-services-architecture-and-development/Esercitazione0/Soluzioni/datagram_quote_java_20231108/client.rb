#!/usr/bin/env ruby

require 'socket'

socket = UDPSocket.new
socket.send "QUOTE", 0, ARGV[0], ARGV[1]
response, _ = socket.recvfrom(4096)
puts response

