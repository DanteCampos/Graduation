import zmq
from constCS import * #-
context = zmq.Context()

p1 = "tcp://"+ HOST +":"+ PORT1 # how and where to connect
s  = context.socket(zmq.REQ)    # create request socket

s.connect(p1)                   # block until connected
s.send(b"Hello world 1")          # send message
message = s.recv()              # block until response
s.send(b"STOP")                 # tell server to stop
print (bytes.decode(message))                 # print result
