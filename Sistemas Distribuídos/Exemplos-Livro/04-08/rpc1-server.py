import pickle
from socket import *
from constRPC import *

class DBList:
	def __init__(self):
		self.value = []

	def append(self, data):
		self.value = self.value + [data]
		return self.value

class Server:
	def __init__(self):
		self.s = socket(AF_INET, SOCK_STREAM)
		self.s.bind((HOST, PORT))
		self.s.listen(1)

		self.dbList = DBList()

	def append(self, data):
		return self.dbList.append(data)

	def run(self):
		while True:
			(conn, addr) = self.s.accept()
			msgrcv = conn.recv(1024)			# wait for a request
			if not msgrcv:
				self.s.close()
				continue
			msgpack = pickle.loads(msgrcv)
			if APPEND == msgpack[0]:			# check what is being requested
				result = self.append(msgpack[1])	# do local call
				msgres = pickle.dumps(result)
				conn.send(msgres)          		# return response
			else:
				pass 					# unsupported request, simply ignore


# Create and start the server
s = Server()
s.run()
