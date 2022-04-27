# o client poy dhmiourgei topika nhmata kai spaei ta vhmata parapanw forres kai ta trexei parallhla
# trexei me to anoigma tou server kai ekteleite se 2 terminal parallhla (xeirokinita anoigoun ta 2 terminal)
# den prolava na kanw to demo sto word gia aythn thn periptwsh
import socket, sys
from multiprocessing import Pool
from random import random
import math



def monte_carlo_pi_part(step):
	cou=0
	for i in range(int(step)):
		x=random()**2
		y=random()**2

		if(math.sqrt(x+y)<=1):
			cou=cou+1
	return cou

#main function
if __name__ == "__main__":
	
	
	
    host = 'localhost'
    port = 5000
	
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
   
	# connect to remote host
    try :
        s.connect((host, port))
    except :
        print ('Unable to connect')
        sys.exit()
	
    print ('Connected to remote host. Start sending messages')
    while(1):
        msg = s.recv(1024).decode("utf-8")
        if not msg:
            continue
        else:
            break
      
    
        
            
    try:       
        steps=msg.split()
        np = 2				
        print(float(steps[0]))
        part_count=[float(steps[0])/np] * np
        part_count= list(map(int,part_count))
        
           
        
        pool = Pool(processes=np) # to pool dhmiourgei aytomata ta nhmata osoi kai oi pyrhnes  

        # parallel map
        
        
        

        count=pool.map(monte_carlo_pi_part, part_count)

            
        print(sum(count))
                
        s.send(str(sum(count)).encode("utf-8"))
    finally:
        s.close()
        sys.exit()
       
    
    					
					
				
			
		
			
