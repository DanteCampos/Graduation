# Calculadora distribuída com gRPC

**Servidor**:  
Disponibiliza as operações ```add(a,b)```, ```mult(a,b)``` e ```pow(a,b)``` para adição, multiplicação e potenciação.  
Conexões são feitas pela porta ```12345```.  

**Cliente**:  
Chama operações add, mult e pow conectando na porta ```12345``` do servidor.

**gRPC**:  
Utilizamos protocol buffers para definir o formato das mensagens recebidas e enviadas, tanto pelo cliente como pelo servidor.  
Definimos a estrutura das mensagens, bem como dos métodos a serem implementados, seus parâmetros e retornos, num arquivo ```.proto```.  
O arquivo ```.proto``` é compilado pelo gRPC para gerar os objetos ```_pb2.py``` e ```_pb2_grpc.py```, que possuem os stubs para lidar com a passagem de mensagens.  
Utilizamos o stub criado para chamar as operações do servidor através de seus métodos, passando a mensagem de entrada instanciada através da setagem de nomes ```(a = 1, b = 2)``` para então receber a mensagem de retorno, também estruturada, em que podemos acessar seus atributos com ```msg.result```, por exemplo.

[**Vídeo Demonstrativo**](https://youtu.be/bNRKtJU8DXQ)
