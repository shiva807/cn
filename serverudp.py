from socket import *
servername=gethostname()
serverport=12000
serverSocket=socket(AF_INET, SOCK_DGRAM)
serverSocket.bind((servername, serverport))
files=["f1.txt","f2.txt","f3.txt","f4.txt","f5.txt"]
#word=serverSocket.recvfrom(2048)
print("Server is ready...")
st=" "
while 1:
   word, clientaddr=serverSocket.recvfrom(2048)
   for i in files:
       fil=open(i, "r")
       y=fil.read().replace("."," ").replace(","," ")
       x=y.strip().split()
       p=word.decode("utf-8")
       if p in x:
          st=st+str(i)+" "
       fil.close()

   if len(st)!=0:
     serverSocket.sendto(bytes(st,"utf-8"), clientaddr)
   else:
     serverSocket.sendto(bytes("Not Found","utf-8"), clientaddr)
   print("sent")
   break


