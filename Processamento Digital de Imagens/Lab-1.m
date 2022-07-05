% Laboratório 1 - Processamento Digital de Imagens
% Daniel Campos da Silva - 201801485

% Para visualizar as imagens, basta descomentar (remover o '%') as linhas 'pause()'

% Questão 1

pkg load image
matriz = [];
linha = []
for j = 1:40
    linha = []
    for i = 1:40
        linha = [linha, i];
    end
    matriz = [matriz; linha];
end

matriz_cinza = mat2gray(matriz);
imshow(matriz_cinza)
%pause()

% Questão 2

imshow(matriz_cinza, [0 2])
%pause()
% A imagem ficou mais escura, indo do preto na esquerda a um cinza na direita

imshow(matriz_cinza, [0.3, 0.7])
%pause()
% Um lado na esquerda é completamente preto, enquanto um na direita é completamente branco
% e entre eles há uma pequena gradação cinza

imshow(matriz_cinza, [])
%pause()
% A imagem vai do preto na esquerda ao branco na direita, mantendo uma gradação uniforme

% Questão 3

matriz_uint8 = im2uint8(matriz_cinza);
imshow(matriz_cinza)
matriz_cinza
%pause()
imshow(matriz_uint8)
matriz_uint8
%pause()

% Na imagem há uma pequena diferença na gradação do preto ao branco
% A matriz_cinza tem valores reais de 0 a 1, enquanto a matriz_uint8 tem valores inteiros de 0 a 255

% Questão 4

matriz2 = [
-0.5, -0.5, -0.2, 0.2, 0.9, 1.2, 1.5;
-0.8, 0.7, 0.72, 0.2, 0.9, 1.2, 1.5;
-0.5, 0.5, 0.2, 0.2, 0.9, 1.2, 1.5;
-0.5, 0.45, 0.2, 0.2, 0.9, 1.2, 1.5;
-0.5, -0.5, 0.42, 0.2, 0.49, 1.2, 1.5
];

matriz2_uint8 = im2uint8(matriz2);
matriz2_gray = mat2gray(matriz2);
matriz2_uint8
imshow(matriz2_uint8)
%pause()
matriz2_gray
imshow(matriz2_gray)
%pause()
% A imagem geerada pelo mat2gray tem uma gradação mais suave,
% a gerada pelo uint8 converte a penúltima coluna para 255, que é mais do que ela deveria

matriz2_convertida = im2double(im2uint8(matriz2))
imshow(matriz2_convertida)
%pause()
% A imagem é idêntica à matriz2_uint8, porém com valores reais de 0 a 1
% As aproximações realizadas por im2uint8 se mantém ao converter com im2double

% Questão 5

imagem5_path = 'Laboratorio_Imagens/Laboratorio_1_5.jpg';
imagem5 = imread(imagem5_path);
size(imagem5) % 206 499 3
whos imagem5 % Name: imagem5 Size: 206x499x3 Bytes: 308382 Class: uint8
imfinfo(imagem5_path)
imshow(imagem5)
%pause()
% imfinfo retorna informações sobre a imagem, como:
% endereço+nome do arquivo, tamanho, formato, tipo de cor, profundidade de bits, etc.

% Questão 6

imagem6_path = 'Laboratorio_Imagens/Laboratorio_1_6.tif';
i = imread(imagem6_path);
imshow(i)
%pause()

imshow(i(end:-1:1, :))
%pause()
% Inverte a imagem verticalmente indo de x = end a x = 1 somando -1 em x

imshow(i(65:198, 65:198))
%pause()
% Seleciona uma região da imagem com x = [65, 198] e y = [65, 198]

imshow(i(1:2:end, 1:2:end))
%pause()
% Diminui a resolução da imagem caminhando em x e y de 2 em 2

plot(i(132, :));
%pause()
% Seleciona a linha 132 da imagem e plota um gráfico em que
% o eixo x é a posição do pixel e o eixo y é o valor do pixel (de 0 a 255)

% Questão 7

zeros(10, 10)
% Gera uma matriz 10x10 de zeros

ones(10, 10)
% Gera uma matriz 10x10 de uns

true(10, 10)
% Gera uma matriz 10x10 de verdadeiros (1s)

false(10, 10)
% Gera uma matriz 10x10 de falsos (0s)

matriz_magic = magic(10);
matriz_magic
sum(matriz_magic) % Soma das colunas
sum(matriz_magic, 2) % Soma das linhas
% Gera uma matriz 10x10 com inteiros de 1 a 10²
% em que coolunas e linhas somam o mesmo valor (505)

rand(10, 10)
% Gera uma matriz 10x com números reais entre 0 e 1

randn(10, 10)
% Gera uma matriz 10x com números reais entre -1 e 0
