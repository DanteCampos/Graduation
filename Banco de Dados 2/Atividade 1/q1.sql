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
