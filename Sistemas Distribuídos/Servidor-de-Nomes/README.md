# Servidor de Nomes com RPyC

**Servidor de Nomes**:  
Disponibiliza as operações ```lookup(name)``` e ```register(name, host, port)``` acessar e modificar os pares (name, host:port).
Pares são armazenados no dicionário ```map```.
Executamos esse servidor como um ```Threaded Server``` do RPyC para que o dicionário não seja recriado para cada conexão, e sim seja compartilhado entre elas.

**Servidores de Aplicação**:  
Dois simples servidores disponibilizam as operações de criptografar e descriptografar, uma string de acordo com uma chave. Ao serem iniciados, sempre registram seus nomes no servidor de nomes.

**Cliente**:  
Para cada palavra na língua inglesa, criptografa e então descriptografa através dos métodos remotos implementados nos servidores de aplicação.
Ao iniciar, se conecta ao servidor de nomes para receber os endereços e portas dos servidores de aplicação.

**English Words**:  
A biblioteca [english-words-py](https://github.com/mwiens91/english-words-py) foi utilizada para obter a lista de palavras a serem criptografadas e descriptografadas.
Para instalá-la, utilize o comando ```pip install english-words```.

[**Vídeo Demonstrativo**](https://youtu.be/EI0FI9JAphs)
