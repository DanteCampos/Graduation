import rpyc
from constCS import *
from rpyc.utils.server import ThreadedServer

class DNS(rpyc.Service):
	def __init__(self):
		self.map = dict()
		
	def register(self, name: str, host: str, port: int):
		print (host, ':', port, '<-', name)
		self.map.update({name: (host, port)})
	
	def lookup(self, name: str) -> tuple:
		print (name, '-> ', end = '')
		if name not in self.map:
			return None
		result = self.map.get(name)
		print (result[0], ':', result[1])
		return result


if __name__ == "__main__":
	server = ThreadedServer(
		DNS(),
		port = DNS_PORT,
		protocol_config={'allow_public_attrs': True,}
	)
	server.start()