-- Questao 1

-- Letra a)

CREATE TABLE cliente (
  codigo int NOT NULL,
  nome varchar(60) NULL,
  sexo varchar(1) NULL,
  CONSTRAINT pkCodigoCliente PRIMARY KEY (codigo)
);

CREATE TABLE produto (
  codigo int NOT NULL,
  nome varchar(60) NULL,
  unidade int NULL,
  preco numeric(10, 2) NULL,
  CONSTRAINT pkCodigoProduto PRIMARY KEY (codigo)
);

CREATE TABLE pedido (
  numero int NOT NULL,
  data date NULL,
  codcli int NOT NULL,
  total numeric(20,2) NOT NULL,
  CONSTRAINT pkCodigoPedido PRIMARY KEY (numero),
  CONSTRAINT fkCodcliPedido FOREIGN KEY (codcli) REFERENCES cliente(codigo)
);

CREATE TABLE itempedido (
  numero int NOT NULL,
  codpro int NOT NULL,
  qtde int NULL,
  valor numeric(20, 2) NULL,
  CONSTRAINT pkNumeroItemPedido PRIMARY KEY (numero, codpro),
  CONSTRAINT fkNumeroItemPedido FOREIGN KEY (numero) REFERENCES pedido(numero),
  CONSTRAINT fkCodproItemPedido FOREIGN KEY (codpro) REFERENCES produto(codigo)
  
);

-- Letra b)

CREATE OR REPLACE FUNCTION atualizaTotalFuncao() RETURNS TRIGGER AS
$f$
BEGIN
  IF TG_OP = INSERT THEN
    UPDATE pedido p
      SET p.total = p.total + NEW.qtde*NEW.valor
      WHERE p.numero = NEW.numero;
  ELSE
    IF TG_OP = UPDATE THEN
      UPDATE pedido p
        SET p.total = p.total - OLD.qtde*OLD.valor + NEW.qtde*NEW.valor
        WHERE p.numero = NEW.numero;
    ELSE
      UPDATE pedido p -- DELETE
        SET p.total = p.total - OLD.qtde*OLD.valor
        WHERE p.numero = OLD.numero;
    END IF
  END IF
END;
$f$ language 'plpgsql';

CREATE TRIGGER atualizaTotalTrigger
  AFTER INSERT OR UPDATE OR DELETE ON itempedido
  FOR EACH ROW EXECUTE PROCEDURE atualizaTotalFuncao();

INSERT INTO cliente(codigo, nome, sexo)
  VALUES (1, 'Carla Silva', 'F');

INSERT INTO produto(codigo, nome, unidade, preco) VALUES
(1, 'Leite integral', 1, 6.50),
(2, 'Cartela de ovos', 18.50),
(3, 'Farinha de trigo', 5.75);

INSERT INTO pedido(numero, data, codcli, total)
VALUES(1, '2022-12-22', 1, 0);

INSERT INTO itempedido(numero, codpro, qtde, valor) VALUES
(1, 1, 1, 6.50)
(1, 2, 2, 18.50)
(1, 3, 1, 5.75);

UPDATE itempedido ip
  SET ip.qtde = 3
  WHERE ip.numero = 1 AND ip.codpro = 2;

DELETE FROM itempedido ip
  WHERE ip.numero = 1 AND ip.codpro = 2;

SELECT * FROM pedido;

-- Letra c)

SELECT c.nome, c.sexo, pe.numero, pe.data, pr.nome
  FROM cliente c
  JOIN pedido pe ON c.codigo = pe.codcli
  JOIN itempedido ip ON ip.numero = pe.numero
  JOIN produto pr ON pr.codigo = ip.codpro;

-- Questao 2

-- Letra a)

CREATE TABLE auditoria(
  nome_tabela varchar(20),
  acao varchar(20),
  data_hora timestamp
);

-- Letra b)

CREATE OR REPLACE FUNCTION insereLog() RETURNS TRIGGER AS
$f$
BEGIN
  INSERT INTO auditoria(nome_tabela, acao, data_hora) VALUES
  (TG_TABLE_NAME, TG_OP, CURRENT_TIMESTAMP());
END;
$f$ language 'plpgsql';

CREATE TRIGGER atualizaLog
  AFTER INSERT OR UPDATE OR DELETE ON cliente
  FOR EACH STATEMENT EXECUTE PROCEDURE insereLog();

CREATE TRIGGER atualizaLog
  AFTER INSERT OR UPDATE OR DELETE ON produto
  FOR EACH STATEMENT EXECUTE PROCEDURE insereLog();

CREATE TRIGGER atualizaLog
  AFTER INSERT OR UPDATE OR DELETE ON pedido
  FOR EACH STATEMENT EXECUTE PROCEDURE insereLog();

CREATE TRIGGER atualizaLog
  AFTER INSERT OR UPDATE OR DELETE ON itempedido
  FOR EACH STATEMENT EXECUTE PROCEDURE insereLog();