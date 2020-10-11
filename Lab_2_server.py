import socket


def main():
	host = '127.0.0.1'

	s = socket.socket()
	s.bind((host, port))

	s.listen(1)
	c,addr = s.accept()

	print "connection from : " + str(addr)

	while True:
		data = c.recv(1024)
		if not data:
			break
		print "client :" + str(data)

		data = raw_input('-->')
		print "sending " + str(data)
		c.send(data)
	c.close()
if __name__ == '__main__':
	main(5000);
