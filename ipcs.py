import os
import sys

path="/home/shivangi/Pictures/port1.txt"
path2="/home/shivangi/Pictures/port2.txt"

li=[]
line=[]
os.mkfifo(path)
print("Ready to receive..")
fifo=open(path, "r")
contents=fifo.read()
line=contents.split("  ")
for i in line:
    print("Received : ",i)
    li.append(i)

fifo.close()
print()
print("Sending data to client.. ")
fifo2=open(path2, "w")
fifo2.write(str(li))
fifo2.close() 
