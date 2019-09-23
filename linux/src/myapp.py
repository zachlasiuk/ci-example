import sys
import socket

device_data = ['data1','data2','data3','data4']

def main():
	# initalize web connection
	s = initWebCon('www.google.com',80)

	# Send rolling collected data
	for data in device_data:
		sendDeviceData(s,data)

def initWebCon(host,port):
        s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        s.connect((host,port))
        return s

def sendDeviceData(s,data):
        try:
                print "Sending: ", data
                s.send(data)
        except:
                print "Error sending device data"

if __name__ in "__main__":
	sys.exit(main())
