CREATE OR REPLACE FUNCTION spIncluirCidade (
    nomeEstado estado.nome%TYPE,
    siglaEstado estado.uf%TYPE,
    nomeCidade cidade.nome%TYPE
)
RETURNS VOID AS $$
DECLARE
    idEstadoFuncao cidade.idEstado%TYPE;
    idCidadeFuncao cidade.idCidade%TYPE;
    populacaoFuncao cidade.populacao%TYPE;
BEGIN
    -- Verifique se o estado já está cadastrado no banco de dados (considere que o país sempre será o Brasil). 
    -- Se o estado estiver cadastrado, capture o seu idEstado;
    SELECT e.idEstado INTO idEstadoFuncao FROM estado e
    WHERE LOWER(e.nome) = LOWER(nomeEstado) AND LOWER(e.uf) = LOWER(siglaEstado);
    
    -- Se o estado não estiver cadastrado, insira-o na tabela estado e capture o idEstado recem inserido.
    IF idEstadoFuncao IS NULL THEN
        SELECT MAX(e.idEstado) + 1 INTO idEstadoFuncao FROM estado e;
        INSERT INTO estado (idEstado, nome, uf, idPais) VALUES (idEstadoFuncao, nomeEstado, siglaEstado, 55);
    END IF;

    -- Insira a cidade no banco de dados.
    -- A população deve ser calculada como a média da população de todas as cidades deste estado mais 4000.
    SELECT MAX(c.idCidade) + 1 INTO idCidadeFuncao FROM cidade c;

    SELECT AVG(c.populacao) INTO populacaoFuncao FROM cidade c WHERE c.idEstado = idEstadoFuncao;
    populacaoFuncao := populacaoFuncao + 4000;

    -- Se a cidade já estiver cadastrada para aquele estado
    IF EXISTS (SELECT * FROM cidade c WHERE LOWER(c.nome) = LOWER(nomeCidade) AND c.idEstado = idEstadoFuncao) THEN
        RAISE NOTICE 'Cidade % já cadastrada', nomeCidade;
    END IF;

    INSERT INTO cidade (idCidade, nome, idEstado, populacao) VALUES (idCidadeFuncao, nomeCidade, idEstadoFuncao, populacaoFuncao);

END;
$$ LANGUAGE 'plpgsql';