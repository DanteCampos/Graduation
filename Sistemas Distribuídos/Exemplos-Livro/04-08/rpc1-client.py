import pickle
from socket import *
from constRPC import *

class Client:
	def __init__(self):
		self.remote_server = ClientStub()

	def run(self):
		print (self.remote_server.append("List item 1"))
		print (self.remote_server.append("List item 2"))


class ClientStub:
	def __init__(self):
		pass

	# Stub for procedure append
	def append(self, data):
		s = socket(AF_INET, SOCK_STREAM)
		s.connect((HOST,PORT))		# one connection per call
		msgpack = (APPEND, data)	# message payload
		msgsnd = pickle.dumps(msgpack)	# serialized message
		s.send(msgsnd)			# send msg to server
		msgrcv = s.recv(1024)		# wait for response
		retval = pickle.loads(msgrcv)	# desserialize response message
		s.close()
		return retval			# pass response to caller

# Create and run the client
c = Client()
c.run()

