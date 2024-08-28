#!/usr/bin/env ruby

require 'socket'

server = TCPServer.new 51000
loop do
  connection = server.accept
  file_name = connection.readline.chomp
  # puts "Filename: '#{file_name}'"
  File.open(file_name, "r") do |f|
    5.times do
      connection.puts f.readline
    end
  end
  connection.close
end
