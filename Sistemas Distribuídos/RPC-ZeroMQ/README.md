# Calculadora distribuída com ZeroMQ

**Servidor**:  
Recebe uma operação do tipo ```a + b```, ```a * b``` ou ```a ** b``` e responde com o resultado com 2 casas decimais.  
Possui duas portas disponíveis: ```8001``` e ```8002```.  
Printa a operação recebida.  

**Cliente**:  
Recebe como argumento do terminal 1 ou 2 como a porta que será conectada (```8001``` ou ```8002```).  
Gera uma operação a op b aleatória a cada segundo.  
```op``` pode ser ```+```, ```*``` ou ```**```.  
```a``` e ```b``` podem ser quaiquer números entre 0 e 10, com 2 casas decimais.  
Printa a operação enviada e o resultado recebido.  

**ZeroMQ**:  
Funciona assim como programação direta nos sockets, com uma operação bloqueante para receber a mensagem do cliente ou enviar a mensagem ao servidor.

[**Vídeo Demonstrativo**](https://youtu.be/bNRKtJU8DXQ)
