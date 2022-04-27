
import socket, sys

from random import random
import math



def monte_carlo_pi_part(step):
	cou=0
	for i in range(step):
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
        				
        print(float(steps[0]))
             
        				
        c=monte_carlo_pi_part(int(float(steps[0])))
        print(c)
            
        s.send(str(c).encode("utf-8"))
        print("pi calc",monte_carlo_pi_part(int(float(steps[0]))))
    finally:
       print('ok')
       s.close()
       sys.exit()
    					
					
				
			
		
			
