#!/usr/bin/env ruby

require 'socket'

socket = TCPSocket.new ARGV[0], ARGV[1]

socket.puts ARGV[2]

i = 1
while ((line = socket.gets) && i <= 5)
  puts line
  i += 1
end

socket.close   
