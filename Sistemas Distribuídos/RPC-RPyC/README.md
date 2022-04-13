# Calculadora distribuída com RPyC

**Servidor**:  
Disponibiliza as operações ```add(a,b)```, ```mult(a,b)``` e ```pow(a,b)``` para adição, multiplicação e potenciação.  
Conexões são feitas pela porta ```12345```.  
É utilizada uma flag na instanciação do servidor para não precisar definir o nome das operações com ```exposed_``` no começo.  

**Cliente**:  
Chama operações ```add```, ```mult``` e ```pow``` conectando na porta ```12345``` do servidor.  

**RpyC**:  
Cliente se conecta ao servidor através de ```conn = rpyc.connect(HOST, port = PORT)```.  
Chamadas de operações do servidor são realizadas através de ```conn```, que representa o servidor e disponibiliza métodos com sintaxe equivalente à de um serviço local.  
Servidor cria um objeto server do tipo ```ForkingServer``` para receber seu próprio processo (poderíamos criar vários processos).  
O objeto server possui uma instância da classe que implementa os métodos chamados, ```solver```.  
A classe implementadora deve ser herdeira de ```rpyc.Service```.  
Os métodos de uma classe implementadora só estão visíveis aos clientes se seus nomes começam com ```exposed_```, portanto utilizamos ```protocol_config={'allow_public_attrs': True,}``` para indicar que todos os métodos são visíveis, mesmo sem ```exposed_```.  

[**Vídeo Demonstrativo**](https://youtu.be/bNRKtJU8DXQ)
