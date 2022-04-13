from constCS import *
import sys
import zmq
from random import *
import time

if sys.argv[1] == '1':
	port = PORT1
elif sys.argv[1] == '2':
	port = PORT2
else:
	print("Wrong arguments")
	exit()

context = zmq.Context()
s  = context.socket(zmq.REQ)
p = f"tcp://{HOST}:{port}"
s.connect(p)

while True:
	a = "{:.2f}".format(random()*10)
	b = "{:.2f}".format(random()*10)
	op = choice(["+", "*", "**"])
	
	send_msg = str.encode(f"{a} {op} {b}")
	s.send(send_msg)
	msg = s.recv()
	result = bytes.decode(msg)
	
	time.sleep(1)
	
	print (a, op, b, '=', result)