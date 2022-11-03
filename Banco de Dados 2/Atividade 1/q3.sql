ALTER TABLE Venda
    ADD CONSTRAINT fkCodVendedor FOREIGN KEY (codVendedor) REFERENCES Vendedor(codVendedor),
    ADD CONSTRAINT fkCodCliente FOREIGN KEY (codCliente) REFERENCES Cliente(codCliente);