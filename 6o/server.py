# import socket programming library 
import socket 

import sys
import time

# import thread module 
from _thread import *
import threading 


class ReadWriteLock: # domh pou periexei locks gia writers kai readers, dinei varythta stou writers
	# polloi readers diavazoun parallhla mono 1 omws writes grafei sthn vash, kai ola ta alla etoimata perhmenoun sthn oura FIFO
    """ A lock object that allows many simultaneous "read locks", but
    only one "write lock." """
	
    def __init__(self):
        self._read_ready = threading.Condition(threading.Lock(  ))
        self._readers = 0

    def acquire_read(self):
        """ Acquire a read lock. Blocks only if a thread has
        acquired the write lock. """
        self._read_ready.acquire(  )
		
        try:
            self._readers += 1
        finally:
            self._read_ready.release(  )
		
    def release_read(self):
        """ Release a read lock. """
        self._read_ready.acquire(  )
        try:
            self._readers -= 1
            if not self._readers:
                self._read_ready.notifyAll(  )
        finally:
            self._read_ready.release(  )

    def acquire_write(self):
        """ Acquire a write lock. Blocks until there are no
        acquired read or write locks. """
        self._read_ready.acquire(  )
		
        while self._readers > 0:
            self._read_ready.wait(  )
	

    def release_write(self):
        """ Release a write lock. """
        self._read_ready.release(  )



def threaded(c): 
	while True: 

		# data received from client 
		data = c.recv(1024).decode("utf-8") 
		if not data:  # periptwsh pou den sthlei kapoia dedomena
			print('Bye') 
			
			# lock released on exit 
			c.close()
			
			break
			

		



	
	



def Main(): 
	host = "localhost" 

	# reverse a port on your computer 
	# in our case it is 8044 but it 
	# can be anything 
	port = 8044
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
	s.bind((host, port)) 
	print("socket binded to post", port) 

	# put the socket into listening mode 
	s.listen(5) 
	print("socket is listening") 
	
	# a forever loop until client wants to exit 
	while True: 

		# establish connection with client 
		c, addr = s.accept() 

		
		 
		print('Connected to :', addr[0], ':', addr[1]) 

		# Start a new thread and return its identifier 
		start_new_thread(threaded, (c,)) 
	s.close() 


if __name__ == '__main__': 
	Main() 
