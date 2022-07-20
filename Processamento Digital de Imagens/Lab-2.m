% Laboratório 2 - Processamento Digital de Imagens
% Daniel Campos da Silva - 201801485

% Para visualizar as questões, basta colocar entre %{ e %} as que deseja ignorar

pkg load image

%{

% Questão 1

imagem1_path = 'Laboratorio_Imagens/Laboratorio_2_1.jpg';
imagem1 = imread(imagem1_path);

bar(imagem1)
title("Histograma da Imagem 2.1")
ylabel("Intensidade")
text(0,255, "Ponto branco na coluna 0")
pause()

stem(imagem1)
title("Stem da Imagem 2.1")
ylabel("Intensidade")
text(0,255, "Ponto branco na coluna 0")
pause()

plot(imagem1)
title("Plot da Imagem 2.1")
ylabel("Intensidade")
text(0,255, "Ponto branco na coluna 0")
pause()



% Questão 2

imagem1_path = 'Laboratorio_Imagens/Laboratorio_2_1.jpg';
imagem1 = imread(imagem1_path);

imshow(imagem1)
pause()
% Para comparação

imshow(imadjust(imagem1))
pause()
% Satura os 1% mais escuros e 1% mais claros

imshow(imadjust(imagem1, [0.4 0.5], []))
pause()
% Pixels com intensidade entre 0.4 e 0.5 são mapeados para o intervalo [0, 1]
% Pixels com intensidade abaixo do intervalo recebem 0, acima do intervalo recebem 1

imshow(imadjust(imagem1, [0 1], [1 0]))
pause()
% Pixels com intensidade entre 0 e 1 (todos) são mapeados para o intervalo [1, 0] (o negativo da imagem)
% Pixels com intensidade abaixo do intervalo recebem 0, acima do intervalo recebem 1

imshow(imadjust(imagem1, [0.5 0.75], [0 1]))
pause()
% Pixels com intensidade entre 0.5 e 0.75 são mapeados para o intervalo [0, 1]
% Pixels com intensidade abaixo do intervalo recebem 0, acima do intervalo recebem 1

imshow(imadjust(imagem1, [ ], [ ], 2))
pause()
% Gamma = 2 define a função de mapeamento dos pixels do intervalo [0.01 0.99] ao [0.01 0.99]


% Questão 3

imagem3_path = 'Laboratorio_Imagens/Laboratorio_2_3.bmp';
imagem3 = imread(imagem3_path);

imshow(imagem3)
pause()

imshow(imadjust(imagem3))
pause()

bar(imagem3)
ylim([0 255])
pause()

bar(imadjust(imagem3))
ylim([0 255])
pause()

% O ajuste equilibra a discrepância entre pixels muito claros e muito escuros
% Nessa imagem, a intensidade dos pixels parece ter aumentado para realizar esse equilíbrio



% Questão 4

g = imread('Laboratorio_Imagens/Laboratorio_2_3.bmp');
figure; % Inicia uma figura
imshow(g); % Mostra a imagem 2.3
pause()

figure;
imhist(g); % Mostra o histograma da imagem: eixo x = intensidade, eixo y = qtd. pixels com a intensidade
ylim('auto'); % Define o limite do eixo y como automático
pause()

hnorm = imhist(g)./numel(g); % Divide o valor de cada barra do histograma pela quantidade de pixels
cdf = cumsum(hnorm); % Soma todas os valores obtidos pela operação acima formando um vetor de somas
x = linspace(0, 1, 256); % x é um espaço linear que vai de 0 a 1 em 256 passos

figure;
plot(x,cdf); % Inicia o plot com eixo x = espaço linear e eixo y = cdf
axis([0 1 0 1]); % limites dos axis atuais
set(gca, 'xtick', 0:.2:1); % tic do eixo x vai de 0 a 1 pulando de 0.2 em 0.2
set(gca, 'ytick', 0:.2:1); % tic do eixo x vai de 0 a 1 pulando de 0.2 em 0.2
xlabel('Valores de Intensidade de Entrada', 'fontsize', 9); % legenda eixo x
ylabel('Valores de Intensidade de Saída', 'fontsize', 9); % legenda eixo y
text(0.18, 0.5, 'Funcao de Transfomacao', 'fontsize', 9); % texto na posição (0.18, 0.5)
pause()



% Questão 5

g1 = imread('Laboratorio_Imagens/Laboratorio_2_5_a.bmp');
g2 = imread('Laboratorio_Imagens/Laboratorio_2_5_b.bmp');
g3 = imabsdiff(g2,g1); % Faz a diferença entre duas imagens considerando o absoluto da subtração
g4 = imcomplement(g3); % Faz o negativo da imagem

% Histogramas têm eixo x = intensidade, eixo y = qtd. pixels com a intensidade
figure('Name', 'Imagem Original'),imshow(g1);
figure('Name', 'Histograma da Imagem Original'), imhist(g1);
figure('Name','Imagem do Fundo'), imshow(g2);
figure('Name','Histograma da Imagem do Fundo'), imhist(g2);
figure('Name', 'Imagem Diferença'), imshow(g3);
figure('Name', 'Histograma da Imagem Diferença'), imhist(g3);
figure('Name','Imagem resultado da subtração complementada'), imshow(g4);
figure('Name','Histograma da Imagem complementada'), imhist(g4);
pause()

disp("Usando g3=g2-g1")
g3 = g2 - g1
g4 = imcomplement(g3);
figure('Name', 'Imagem Diferença'), imshow(g3);
figure('Name', 'Histograma da Imagem Diferença'), imhist(g3);
figure('Name','Imagem resultado da subtração complementada'), imshow(g4);
figure('Name','Histograma da Imagem complementada'), imhist(g4);
pause()

% Foi tudo idêntico a usar g3 = imabsdiff(g2,g1);

disp("Usando g3=g1-g2")
g3 = g1 - g2
g4 = imcomplement(g3);
figure('Name', 'Imagem Diferença'), imshow(g3);
figure('Name', 'Histograma da Imagem Diferença'), imhist(g3);
figure('Name','Imagem resultado da subtração complementada'), imshow(g4);
figure('Name','Histograma da Imagem complementada'), imhist(g4);
pause()

% A imagem da diferença quase que completamente preta
% O complemento da imagem foi quase que completamente branco

% A função imabsdiff impede que valores negativos sejam tratados como 0s
% Utilizar apenas a subtração simples ignora diferenças negativas



% Questão 6

imagem_6 = imread('Laboratorio_Imagens/Laboratorio_2_6.bmp');

imshow(imagem_6)
pause()

imshow(im2bw(imagem_6, 0.5)) % Binarização com limiar 50%
pause()
% Dividiu bem a imagem entre o fundo (branco) e as silhuetas das ferramentas (preto)

imshow(im2bw(imagem_6, graythresh(imagem_6))) % Binarização com limiar = nível de Otsu
pause()
% Dividiu melhor ainda, as silhuetas estão mais grossas, matendo mais da imagem original



% Questão 7

imagem_6 = imread('Laboratorio_Imagens/Laboratorio_2_6.bmp');
imagem_6_bin_20 = im2bw(imagem_6, 0.2); % Binarização com limiar 20%
imagem_6_bin_60 = im2bw(imagem_6, 0.6); % Binarização com limiar 60%

% A imagem foi convertida para double no histograma para bater com a escala dos outros histogramas
figure('Name', 'Imagem Original'), imshow(imagem_6);
figure('Name', 'Histograma da Imagem Original'), imhist(im2double(imagem_6));

figure('Name', 'Imagem Binarizada em 20%'), imshow(imagem_6_bin_20);
figure('Name', 'Histograma da Binarizada em 20%'), imhist(imagem_6_bin_20);

figure('Name', 'Imagem Binarizada em 60'), imshow(imagem_6_bin_60);
figure('Name', 'Histograma da Binarizada em 60%'), imhist(imagem_6_bin_60);
pause()

% Podemos ver no histograma da imagem original que não há pixel com intensidade abaixo de 20%
% Portanto, binarizá-la com 20% torna todos os pixels brancos, logo seu histograma só tem pixels em x=1
% Na binarização com 60%, como vemos no histograma original, há muitos pixels de cada lado do 0.6
% O que cria uma distribuição razoável, como vemos no histograma da imagem binarizada em 60%

imagem_3 = imread('Laboratorio_Imagens/Laboratorio_2_3.bmp');
imagem_3_Otsu = im2bw(imagem_3, graythresh(imagem_3));

figure('Name', 'Imagem Original'), imshow(imagem_3);
figure('Name', 'Histograma da Imagem Original'), imhist(im2double(imagem_3));

figure('Name', 'Imagem Binarizada com Otsu'), imshow(imagem_3_Otsu);
figure('Name', 'Histograma da Binarizada com Otsu'), imhist(imagem_3_Otsu);
pause()

% A imagem binarizada com o método Otsu tem classes "branca" e "preta" com variância mínima
% e separa bem o que está à frente da imagem do seu fundo



% Questão 8

imagem_8 = imread('Laboratorio_Imagens/Laboratorio_2_8.tif');

figure('Name', 'Imagem Original'), imshow(imagem_8);

filtro = ones(5,5);
filtro = filtro/(5*5);
imagem_8_filtro_5 = imfilter(imagem_8, filtro);
figure('Name', 'Imagem Com Filtro de Média 5x5'), imshow(imagem_8_filtro_5);

filtro = ones(7,7);
filtro = filtro/(7*7);
imagem_8_filtro_7 = imfilter(imagem_8, filtro);
figure('Name', 'Imagem Com Filtro de Média 7x7'), imshow(imagem_8_filtro_7);

filtro = ones(9,9);
filtro = filtro/(9*9);
imagem_8_filtro_9 = imfilter(imagem_8, filtro);
figure('Name', 'Imagem Com Filtro de Média 9x9'), imshow(imagem_8_filtro_9);

filtro = ones(25,25);
filtro = filtro/(25*25);
imagem_8_filtro_25 = imfilter(imagem_8, filtro);
figure('Name', 'Imagem Com Filtro de Média 25x25'), imshow(imagem_8_filtro_25);

filtro = ones(31,31);
filtro = filtro/(31*31);
imagem_8_filtro_31 = imfilter(imagem_8, filtro);
figure('Name', 'Imagem Com Filtro de Média 31x31'), imshow(imagem_8_filtro_31);

% Quanto maior o tamanho do filtro, maior a suavização da imagem
% Com isso ela vai ficando mais borrada e perdendo detalhes finos
% Porém abranda picos de intensidade

imagem_8_filtro_mediana = medfilt2(imagem_8);
figure('Name', 'Imagem Com Filtro de Mediana'), imshow(imagem_8_filtro_mediana);
pause()

% A mediana borra menos a imagem, pois usa valores já presentes nos pixels da vizinhança



% Questão 9

f = imread('Laboratorio_Imagens/Laboratorio_2_8.tif'); % Lê imagem 2.8
w4 = fspecial('laplacian',0); % Cria filtro de Laplaciano
w8 = [1 1 1; 1 -8 1; 1 1 1]; % Cria filtro 3x3
f = im2double(f); % Converte matriz da imagem para double
g4 = f - imfilter(f, w4, 'replicate'); % Diferença entre imagem original e filtrada pelo filtro Laplaciano
g8 = f - imfilter(f, w8, 'replicate'); % Diferença entre imagem original e filtrada pelo filtro 3x3
% 'replicate' apenas trata o caso das bordas como se a imagem fosse "esférica"
imshow(f); % Mostra imagem original
figure, imshow(g4); % Mostra diferença imagem original com a com filtro Laplaciano
figure, imshow(g8); % Mostra diferença imagem original com a com filtro 3x3
pause()

% O filtro laplaciano é 3x3 e tem parâmetro alpha = 0
% O filtro 3x3 em w8 é uma variante do laplaciano

%}

k = imread('Laboratorio_Imagens/Laboratorio_2_6.bmp'); % Lê a imagem 2.6
f = im2double(k); % Converte a matriz da imagem para double
f1 = imnoise(f,'salt & pepper', 0.6); % Adiciona ruido de sal e pimenta à imagem (aleatório)
f2 = imnoise(f,'salt & pepper', 0.6);
f3 = imnoise(f,'salt & pepper', 0.6);
f4 = imnoise(f,'salt & pepper', 0.6);
f5 = imnoise(f,'salt & pepper', 0.6);
f6 = imnoise(f,'salt & pepper', 0.6);
f7 = imnoise(f,'salt & pepper', 0.6);
f8 = imnoise(f,'salt & pepper', 0.6);
f9 = imnoise(f,'salt & pepper', 0.6);
f10 = imnoise(f,'salt & pepper', 0.6);
fm = (f1 + f2 + f3 + f4 + f5 + f6 + f7 + f8 + f9 + f10)/10;
% fm é uma média de todas as imagens com ruido de sal e pimenta
subplot(2,3,1);imshow(f) % Acrescenta imagem ao subplot
subplot(2,3,2);imshow(f1)
subplot(2,3,3);imshow(f2)
subplot(2,3,4);imshow(f3)
subplot(2,3,5);imshow(f4)
subplot(2,3,6);imshow(f5)
figure
subplot(2,3,1);imshow(f6)
subplot(2,3,2);imshow(f7)
subplot(2,3,3);imshow(f8)
subplot(2,3,4);imshow(f9)
subplot(2,3,5);imshow(f10)
subplot(2,3,6);imshow(fm)
pause()

% Vimos na figura 1 a imagem original e 5 variações com ruido de sal e pimenta acrescidos
% Na figura 2 temos mais 5 variações com ruído e então a média das 10 imagens ruidosas