% Laboratório 2 - Processamento Digital de Imagens
% Daniel Campos da Silva - 201801485

% Para visualizar as imagens, basta descomentar (remover o '%') as linhas 'pause()'

% Questão 1

imagem1_path = 'Laboratorio_Imagens/Laboratorio_2_1.jpg';
imagem1 = imread(imagem1_path);
bar(imagem1)
pause()

stem(imagem1)
pause()

plot(imagem1)
pause()