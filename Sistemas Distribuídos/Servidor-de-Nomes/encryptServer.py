import rpyc
from constCS import *
from rpyc.utils.server import ForkingServer

class encryptServer(rpyc.Service):
	def encrypt(self, string: str, key: int) -> str:
		encrypted = str()
		for char in string:
			char = chr(ord(char) + key)
			encrypted += char
		print (string, '+', key, '-> ', encrypted)
		return encrypted

if __name__ == "__main__":
	server = ForkingServer(
		encryptServer(),
		port = ENCRYPT_PORT,
		protocol_config={'allow_public_attrs': True,}
	)
	
	dns = rpyc.connect(DNS_HOST, port = DNS_PORT)
	dns.root.register(ENCRYPT_NAME, ENCRYPT_HOST, ENCRYPT_PORT)
	server.start()