import grpc
from concurrent import futures
import time
import calc_pb2_grpc as pb2_grpc
import calc_pb2 as pb2
from constCS import *

class Calculator(pb2_grpc.CalculatorServicer):
	def add(self, request, context):
		return pb2.OutNumber(result = request.a + request.b)
	
	def mult(self, request, context):
		return pb2.OutNumber(result = request.a * request.b)
		
	def pow(self, request, context):
		return pb2.OutNumber(result = request.a ** request.b)

def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    pb2_grpc.add_CalculatorServicer_to_server(Calculator(), server)
    server.add_insecure_port(f'[::]:{PORT}')
    server.start()
    server.wait_for_termination()


if __name__ == '__main__':
    serve()