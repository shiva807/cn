import os
import sys

path="/home/shivangi/Pictures/port1.txt"
path2="/home/shivangi/Pictures/port2.txt"

print("Enter sentences:\n")
fifo=open(path, "w")
while True:
    msg=input()
    if msg!='end':
        fifo.write(msg)
        fifo.write("  ")
    else:
         break

fifo.close()
os.mkfifo(path2)
fifo2=open(path2, "r")
#lis=fifo2.read()
for i in fifo2:
    print(i)
fifo2.close()

