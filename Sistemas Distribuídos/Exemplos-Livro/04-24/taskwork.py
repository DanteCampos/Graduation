import zmq, time, pickle, sys
from constPipe import *  #-

context = zmq.Context()
me = str(sys.argv[1])
r  = context.socket(zmq.PULL)     # create a pull socket
p1 = "tcp://"+ SRC1 +":"+ PORT1   # address first task source
p2 = "tcp://"+ SRC2 +":"+ PORT2   # address second task source
r.connect(p1)                     # connect to task source 1
r.connect(p2)                     # connect to task source 2

print (me + " started")

while True:
	work = pickle.loads(r.recv())   # receive work from a source
	print (me + " received " + str(work[1]) + " from " + work[0])
	time.sleep(work[1]*0.01)        # pretend to work
