import grpc
import calc_pb2_grpc as pb2_grpc
import calc_pb2 as pb2
from constCS import *

def run():
	channel = grpc.insecure_channel(f"{HOST}:{PORT}")
	stub = pb2_grpc.CalculatorStub(channel)
	a = 2.5
	b = 3.0

	# Add
	result = stub.add(pb2.InNumbers(a=a, b=b)).result
	print (a, '+', b, '=', result)

	# Mult
	result = stub.mult(pb2.InNumbers(a=a, b=b)).result
	print (a, '*', b, '=', result)

	# Pow
	result = stub.pow(pb2.InNumbers(a=a, b=b)).result
	print (a, '**', b, '=', result)
	
if __name__ == '__main__':
    run()