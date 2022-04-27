import sys
import socket

def main(): # καλείται ο client
   soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM) #dhmiourgia socket
   host = 'localhost' #h syndesh
   port = 5000
   try:
      soc.connect((host, port)) # connection
   except:
      print("Connection Error")
      sys.exit() 
   print("Type READ and the code of the flight ") #to menu
   print("Type WRITE and write the code of the flight (space) the condition of the flight (space) the time (depart/arrvie) you can also modify existed flight")
   print("Type DELETE and the flight id to delete the flight")
   print("Type EXIT to stop the connection")
   message = input(" -> ")
   while message != 'EXIT': # stamataei o client alla den stamataw ton server giati yparxoun kialoi clients
      soc.sendall('{}'.format(message).encode("utf8")) # apostolh ths entolhs
      msg = soc.recv(1024).decode("utf-8") # paralavh apanthshs
     
      print(msg) # print tou mynhmatos
      message = input(" -> ")
 
  
   soc.close()
if __name__ == "__main__":
   main()
