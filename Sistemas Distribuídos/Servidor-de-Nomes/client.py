import rpyc
from english_words import *
from constCS import *

dns = rpyc.connect(DNS_HOST, port = DNS_PORT)

enc = dns.root.lookup(ENCRYPT_NAME)
dec = dns.root.lookup(DECRYPT_NAME)

if enc is None or dec is None:
	quit()

encrypter = rpyc.connect(enc[0], port = enc[1])
decrypter = rpyc.connect(dec[0], port = dec[1])

key = 15
for word in english_words_lower_set:
	encrypted = encrypter.root.encrypt(word, key)
	decrypted = decrypter.root.decrypt(encrypted, key)
	print(word, '->', encrypted, '->', decrypted)