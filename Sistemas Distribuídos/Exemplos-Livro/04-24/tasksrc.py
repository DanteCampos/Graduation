import zmq, time, pickle, sys, random
from constPipe import * #-

context = zmq.Context() 
me  = str(sys.argv[1])
s   = context.socket(zmq.PUSH)        # create a push socket
src = SRC1  if me == '1' else SRC2    # check task source host
prt = PORT1 if me == '1' else PORT2   # check task source port
p   = "tcp://"+ src +":"+ prt         # how and where to connect
s.bind(p)                             # bind socket to address

for i in range(100):                  # generate 100 workloads
	time.sleep(1)
	workload = random.randint(1, 100)   # compute workload
	s.send(pickle.dumps((me,workload))) # send workload to worker
