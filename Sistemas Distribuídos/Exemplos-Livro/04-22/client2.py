import zmq
from constCS import * #-
context = zmq.Context()

p2 = "tcp://"+ HOST +":"+ PORT2 # how and where to connect
s  = context.socket(zmq.REQ)    # create request socket

s.connect(p2)                   # block until connected
s.send(b"Hello world 2")        # send message
message = s.recv()              # block until response
#s.send("STOP")                 # tell server to stop
print (bytes.decode(message))   # print result
