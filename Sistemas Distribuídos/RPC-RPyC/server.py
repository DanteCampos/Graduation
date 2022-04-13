import rpyc
from constCS import *
from rpyc.utils.server import ForkingServer

class solver(rpyc.Service):
	def add(self, a, b):
		return a+b
	
	def mult(self, a, b):
		return a*b
	
	def pow(self, a, b):
		return a**b

if __name__ == "__main__":
	server = ForkingServer(
		solver(),
		port = PORT,
		protocol_config={'allow_public_attrs': True,}
	)
	server.start()