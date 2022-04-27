import socket, threading,sys 
from threading import Thread 
from time import perf_counter
from math import pi as mathPi

n=100000000
NUMBEROFCLIENTS=2
pi=[]

part_count=[n/NUMBEROFCLIENTS] * NUMBEROFCLIENTS
part_count1= list(map(int,part_count))
class ClientThread(Thread): 
 
    def __init__(self,ip,port):  #dimiourgia twn connection kai to trexoume mesa se ena thread
        Thread.__init__(self) 
        
        self.ip = ip 
        self.port = port 
        print ("[+] New server socket thread started for " + ip + ":" + str(port)) 

            
                
def send_msg(sock): #apostolh mynhmatos
    while True:
            sock.send(str(part_count[0]).encode('utf-8'))
            break

def recv_msg(sock): #paralavh mynhmatos
        while True:
            data = sock.recv(1024).decode('utf-8')
            print(data)
            pi.append(float(data)) #dhmiourgia tou pi
            print( "Server received data:", int(data))
            if(len(threads)==2): #o arithmos twn client, an thelame parapanw tha mporousame na dwsoume ston xrhsth na valei arithmo kai na naoiksei antistoixous clients
                print ("Esitmated value of Pi:: ", sum(pi)/(n*1.0)*4) # ypologismos tou pi
                t2 = perf_counter()
                print('Sequential program results with {} steps' .format(n))
                print('Difference between estimated pi and math.pi = {}' .format(abs(sum(pi)/(n*1.0)*4 - mathPi)))
                print('Time to compute = {} seconds' .format(t2-t1))
                sys.exit()
            if not data:
                continue
            else:    
                break
                     
# Multithreaded Python server : TCP Server Socket Program Stub
TCP_IP = '0.0.0.0' 
TCP_PORT = 5000 
BUFFER_SIZE = 20  # Usually 1024, but we need quick response 

tcpServer = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
tcpServer.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) 
tcpServer.bind((TCP_IP, TCP_PORT)) 
threads = [] 
 
while True:
    lock1 = threading.Lock()
    tcpServer.listen(2) 
    print ("Multithreaded Python server : Waiting for connections from TCP clients...") 
    (conn, (ip,port)) = tcpServer.accept() 
    newthread = ClientThread(ip,port) 
    threads.append(newthread) 
    t1 = perf_counter()
    lock1.acquire()
    Thread(target=send_msg, args=(conn,)).start()
    lock1.release()
   
    lock1.acquire()
    recv_msg(conn)
    lock1.release()
    
   
sys.exit()

    