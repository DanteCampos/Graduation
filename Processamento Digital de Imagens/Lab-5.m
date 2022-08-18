% Laboratório 5 - Processamento Digital de Imagens
% Daniel Campos da Silva - 201801485

% Para visualizar as questões, basta colocar entre %{ e %} as que deseja ignorar

pkg load image

%{


% Questão 1
filter = [-1,-1,-1;-1,8,-1;-1,-1,-1];
img_5_1 = imread("Laboratorio_Imagens/Laboratorio_5_1.tif");
img_5_1_filtered = imfilter(img_5_1, filter);
figure('Name', 'Imagem original'), imshow(img_5_1);
figure('Name', 'Imagem filtrada'), imshow(img_5_1_filtered);
pause()

% O filtro realça grandes diferenças entre um pixel e sua vizinhança
% Vemos três pontos brilhantes no círculo interno da imagem que se destacam após a filtragem
% Além disso, destacam-se as bordas do círculo mais externo e do mais interno

% Questão 2

A = imread('Laboratorio_Imagens/Laboratorio_5_2.bmp'); % Imagem original
B = im2bw(A, graythresh(A)); % Binariza a imagem com um threshold
C = ~B; % Inverte a imagem: preto vira branco, branco vira preto
D = bwdist(C); % Cada pixel recebe o valor da distância euclidiana até o pixel não 0 mais próximo
L = watershed(-D); % O watershed divide a imagem em regiões de intensidade similar
w = L == 0; % Binariza imagem: preto vira branco, todo o resto vira preto
g2 = B | w; % Faz a união das imagens B e w: preto se é preto em ambos, branco se é branco em qualquer um

figure('Name', 'A'), imshow(A);
figure('Name', 'B'), imshow(B);
figure('Name', 'C'), imshow(C);
figure('Name', 'D'), imshow(D, []);
figure('Name', 'L'), imshow(label2rgb(L,'jet',[.5 .5 .5]));
figure('Name', 'w'), imshow(w);
figure('Name', 'g2'), imshow(g2);
pause()

% Questão 3

f = imread('Laboratorio_Imagens/Laboratorio_5_3.bmp'); % Lê imagem 5_3.bmp
hf = imhist(f); % Calcula histograma da imagem
figure;
imshow(f); % Mostra imagem f
figure;
plot(hf); % Plota histograma de f
T1 = 0.5 * (double(min(f(:))) + double(max(f(:)))); % Threshold = média dos valores mínimo e máximo dos pixels da imagem
done = false; % Flag para repetição do loop
while ~done % Enquanto não estiver terminado, obtém um melhor threshold
g = f >= T1; % g recebe a imagem binarizada: pixels com valor maior ou igual a T1 viram branco, o resto preto
T1next = 0.5 * (mean(f(g)) + mean(f(~g))); % Calcula o próximo threashold pela média das médias da imagem binarizada e ivertida
done = abs(T1 - T1next) < 0.5; % Aceitamos o erro absoluto de 0.5 para convergência do threshold
T1 = T1next; % Itera T1 para o próximo threshold
end
T2 = T1/255; % T2 = threshold T1, porém com valor normalizado para entre 0 e 1
s1 = im2bw(f,T2); % Binariza a imagem original f com o threshold T2
figure;
imshow(s1); % Mostra a imagem binarizada
pause()

%}

% Questão 4

% Declara a função Laboratorio_5_4b que recebe f, S e T como parâmetros e retorna [g, NR, SI, TI]
function [g, NR, SI, TI] = Laboratorio_5_4b(f, S, T) 
f = double(f); % Converte f para double
if numel(S) == 1 % Se S possui apenas 1 elemento
    SI = f == S; % SI recebe a imagem binarizada: pixels com valor igual a S viram branco, o resto preto
    S1 = S; %S1 recebe S
else % Se S possui mais de 1 elemento
    SI = bwmorph(S, 'shrink', Inf); % Reduz S: buracos viram 1 único pixel em seu centro, objetos com buracos viram anéis passando pelos centros dos buracos
    J = find(SI); % Retorna vetor com os íncides de cada elemento não nulo de SI
    S1 = f(J); % S1 recebe os valores de f nas posições J
end
TI = false(size(f)); % TI recebe uma imagem de mesmo tamanho que f, preenchida com 0
for K = 1:length(S1) % Para K = índices de S1
    seedvalue = S1(K); % seedvalue recebe o valor de S1 na posição K
    S = abs(f - seedvalue) <= T; % S recebe f binarizada: pixels com valor distância de seedvalue menor ou igual a T recebem branco, o resto preto
    TI = TI | S; % T1 recebe a união de TI e S
end
% Reconstrói a imagem T1 identificando os "pedaços" similares a SI e identifica os objetos da imagem resultante pela matriz g, e o número de objetos por NR
[g, NR] = bwlabel(imreconstruct(SI, TI));
pause()

