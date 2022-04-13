import rpyc
from constCS import *

conn = rpyc.connect(HOST, port = PORT)

a = 2.5
b = 3.0
print (a, '+', b, '=', conn.root.add(a,b))
print (a, '*', b, '=', conn.root.mult(a,b))
print (a, '**', b, '=', conn.root.pow(a,b))