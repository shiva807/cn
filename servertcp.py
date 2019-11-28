from socket import *
servername=gethostname()
serverport=12000
serverSocket=socket(AF_INET, SOCK_STREAM)
serverSocket.bind((servername, serverport))
serverSocket.listen(1)
print("Server is ready...")
while 1:
   count=0
   connSocket, clientaddr= serverSocket.accept()  
   str2=connSocket.recv(1024).decode("utf-8")
   lis1=[]
   lis1=str2.split(" ")
   file1=open(lis1[0], "r")
   str3=file1.read()
   lis2=[]
   lis2=str3.split(" ")
   for i in lis2:
       if i==lis1[1]:
          count+=1
   connSocket.send(str(count).encode("utf-8"))
   file1.close()
connSocket.close()


