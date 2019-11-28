from socket import *
servername=gethostname()
serverport=12000
clientSocket=socket(AF_INET, SOCK_DGRAM)
word=input("Enter word to be searched: ")
clientSocket.sendto(bytes(word,"utf-8"), (servername, serverport))
filecontents, serveraddr=clientSocket.recvfrom(2048)
print("From server:\n", filecontents.decode("utf-8"))
clientSocket.close()



