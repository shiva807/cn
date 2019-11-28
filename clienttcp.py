from socket import *
servername=gethostname()
serverport=12000
clientSocket=socket(AF_INET, SOCK_STREAM)
clientSocket.connect((servername, serverport))
str1=input("Enter the filename and word :")
clientSocket.send(str1.encode("utf-8"))
wordcount=clientSocket.recv(1024).decode("utf-8")
print("Wordcount=", wordcount)
clientSocket.close()


