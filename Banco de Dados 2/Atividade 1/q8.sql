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