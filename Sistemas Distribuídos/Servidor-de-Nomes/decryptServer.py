import rpyc
from constCS import *
from rpyc.utils.server import ForkingServer

class decryptServer(rpyc.Service):
	def decrypt(self, string: str, key: int) -> str:
		decrypted = str()
		for char in string:
			char = chr(ord(char) - key)
			decrypted += char
		print (string, '-', key, '-> ', decrypted)
		return decrypted

if __name__ == "__main__":
	server = ForkingServer(
		decryptServer(),
		port = DECRYPT_PORT,
		protocol_config={'allow_public_attrs': True,}
	)
	
	dns = rpyc.connect(DNS_HOST, port = DNS_PORT)
	dns.root.register(DECRYPT_NAME, DECRYPT_HOST, DECRYPT_PORT)
	server.start()
