
import multiprocessing
from random import random
from multiprocessing import Pool
from time import perf_counter
from math import pi as mathPi
import math


def monte_carlo_pi_part(n):
    
    count = 0
    for i in range(n):
        x=random()**2
        y=random()**2

        
        # if it is within the unit circle
        if (math.sqrt(x + y) <= 1):
            count=count+1
        
   
    return count


if __name__=='__main__':
    
    np = multiprocessing.cpu_count()
    print ('You have {0:1d} CPUs'.format(np))

    # ta vhmata touypologismou
    n = 100000000
    
    # iterable with a list of points to generate in each worker
    # each worker process gets n/np number of points to calculate Pi from

    part_count=[n/np] * np
    part_count= list(map(int,part_count))

    
    pool = Pool(processes=np) # to pool dhmiourgei aytomata ta nhmata osoi kai oi pyrhnes  

    # parallel map
    
    
    t1 = perf_counter()

    count=pool.map(monte_carlo_pi_part, part_count)

    t2 = perf_counter()

    print('Sequential program results with {} steps' .format(n))
   
    print('Difference between estimated pi and math.pi = {}' .format(abs(sum(count)/(n*1.0)*4 - mathPi)))
    print('Time to compute = {} seconds' .format(t2-t1))

    print ("Esitmated value of Pi:: ", sum(count)/(n*1.0)*4)  