import sys
import socket

# initalize web connection
s = initWebConnection('localhost',50005)

# Send collected data
s.send('Device data')

# Process message return
data=s.recv(1024)
print 'recieved: ',data
s.close()

def initWebConnection(server_host,server_port):
	s = socket(AF_INET,SOCK_STREAM)
	s.connect((server_host,server_port))
	return s
