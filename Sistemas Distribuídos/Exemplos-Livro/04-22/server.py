import zmq
from constCS import * #-
context = zmq.Context()

p1 = "tcp://"+ HOST +":"+ PORT1 # how and where to connect
p2 = "tcp://"+ HOST +":"+ PORT2 # how and where to connect

s  = context.socket(zmq.REP)    # create reply socket
s.bind(p1)                      # bind socket to address
s.bind(p2)                      # bind socket to address

while True:
	msg = s.recv()				# wait for incoming message
	decoded_msg = bytes.decode(msg)		# decode received message
	if not "STOP" in decoded_msg:     	# if not to stop...
		sent_msg = decoded_msg + "*"		# append "*" to message
		s.send(str.encode(sent_msg))	# encode and send message
	else:
		break		# break out of loop and end
