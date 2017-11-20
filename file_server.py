#credits - srnit
import socket
s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host=socket.gethostname();
port=12346;
s.bind((host,port));
s.listen(5);
addrclient,addr=s.accept();
print ("server listening");
fread=open("README.md",'rb');    #file name here
l=fread.read(1024);
while (l):
	addrclient.send(l);
	print ('sent',l);
	l=fread.read(1024);
print ("data sent");
fread.close();
addrclient.close();
s.close()
    