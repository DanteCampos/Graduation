-- Daniel Campos da Silva, 25/10/2022
-- Ciência da Computação
-- Banco de Dados 2

-- Atividade 1

-- Questão 1

CREATE TABLE TipoProduto(
    codTipo INTEGER NOT NULL,
    descricao VARCHAR(120) NOT NULL,
    CONSTRAINT pkCodTipo PRIMARY KEY (codTipo)
);

CREATE TABLE TipoProduto(
    codTipo INTEGER NOT NULL,
    descricao VARCHAR(120) NOT NULL,
    CONSTRAINT pkCodTipo PRIMARY KEY (codTipo)
);

CREATE TABLE Produto(
    codPro INTEGER NOT NULL,
    descricao VARCHAR(120) NOT NULL,
    preco NUMERIC(10, 2) NOT NULL,
    codTipo INTEGER NOT NULL,
    CONSTRAINT pkCodPro PRIMARY KEY (codPro),
    CONSTRAINT fkCodTipo FOREIGN KEY (codTipo) REFERENCES TipoProduto(codTipo)
);

CREATE TABLE Cliente(
    codCliente INTEGER NOT NULL,
    nome VARCHAR(120) NOT NULL,
    cpf VARCHAR(11) NOT NULL,
    CONSTRAINT pkCodCliente PRIMARY KEY (codCliente)
);

CREATE TABLE Vendedor(
    codVendedor INTEGER NOT NULL,
    nome VARCHAR(120) NOT NULL,
    rg VARCHAR(15) NOT NULL,
    salario NUMERIC(10, 2) NOT NULL,
    CONSTRAINT pkCodVendedor PRIMARY KEY (codVendedor)
);

CREATE TABLE Venda(
    numero INTEGER NOT NULL,
    data DATE NOT NULL,
    valorFrete NUMERIC(10, 2) NOT NULL,
    CONSTRAINT pkNumero PRIMARY KEY (numero)
);

CREATE TABLE VendaProduto(
    numero INTEGER NOT NULL,
    codPro INTEGER NOT NULL,
    CONSTRAINT fkNumero FOREIGN KEY (numero) REFERENCES Venda(numero),
    CONSTRAINT fkCodPro FOREIGN KEY (codPro) REFERENCES Produto(codPro)
);

-- Questão 2

ALTER TABLE Venda
    ADD COLUMN codVendedor INTEGER NOT NULL,
    ADD COLUMN codCliente INTEGER NOT NULL;

-- Questão 3

ALTER TABLE Venda
    ADD CONSTRAINT fkCodVendedor FOREIGN KEY (codVendedor) REFERENCES Vendedor(codVendedor),
    ADD CONSTRAINT fkCodCliente FOREIGN KEY (codCliente) REFERENCES Cliente(codCliente);

-- Questão 4

ALTER TABLE Produto
    ADD unidade INTEGER NOT NULL;

-- Questão 5

ALTER TABLE Cliente
    ADD telefone VARCHAR(20) NOT NULL,
    ADD endereco VARCHAR(120) NOT NULL,
    ADD email VARCHAR(120) NOT NULL;

-- Questão 6

ALTER TABLE VendaProduto
    ADD quantidade INTEGER NOT NULL,
    ADD precoUnitario NUMERIC(10, 2) NOT NULL;

-- Questão 7 não precisa de solução

-- Questão 8
-- Inserir 2 produtos e 1 venda (e os outros dados necessários)

INSERT INTO TipoProduto(codTipo, descricao)
    VALUES (1, 'Móvel');

INSERT INTO TipoProduto(codTipo, descricao) 
    VALUES (2, 'Eletrônico');

INSERT INTO Produto(codPro, descricao, preco, codTipo, unidade)
    VALUES (1, 'Sofá-cama', 850.00, 1, 10);

INSERT INTO Produto(codPro, descricao, preco, codTipo, unidade)
    VALUES (2, 'Computador de mesa', 2500.00, 2, 30);

INSERT INTO Vendedor(codVendedor, nome, rg, salario)
    VALUES (1, 'Raíssa Meirelles', '019924058', 2300.00);

INSERT INTO Cliente(codCliente, nome, cpf, telefone, endereco, email)
    VALUES (1, 'Rafael da Silva', '123456789', '+55062999999999', 'Jardim América', 'rafael.da.silva@ufg.br');

INSERT INTO Venda(numero, data, valorfrete, codvendedor, codcliente)
    VALUES (1, '2022-11-01', 40.00, 1, 1);

INSERT INTO vendaProduto(numero, codPro, quantidade, precoUnitario)
    VALUES (1, 2, 2, 2500.00);