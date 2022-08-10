% Laboratório 3 - Processamento Digital de Imagens
% Daniel Campos da Silva - 201801485

% Para visualizar as questões, basta colocar entre %{ e %} as que deseja ignorar

pkg load image

%{
% Questão 1
img_3_1 = imread("Laboratorio_Imagens/Laboratorio_3_1.bmp");
img_3_1_red = img_3_1(:,:,1);
img_3_1_green = img_3_1(:,:,2);
img_3_1_blue = img_3_1(:,:,3);

figure('Name', 'Imagem colorida'), imshow(img_3_1);
figure('Name', 'Canal Vermelho'), imshow(img_3_1_red);
figure('Name', 'Canal Verde'), imshow(img_3_1_green);
figure('Name', 'Canal Azul'), imshow(img_3_1_blue);

img_3_1_concat = cat(3, img_3_1_red, img_3_1_green, img_3_1_blue);
figure('Name', 'Imagem concatenada'), imshow(img_3_1_concat);

pause()


% Questão 2

RGB = imread('Laboratorio_Imagens/Laboratorio_3_2.png');
[X,map] = rgb2ind(RGB); % rgb2ind(RGB, 256) não funciona no Octave
figure
imshow(X,map)
[Y, newmap] = imapprox(X, map, 10); % A função imapprox não está implementada no Octave
figure
imshow(Y,newmap)
pause()
% A função rgb2ind obtém o par Interiro e Mapa de 256 cores pra cada canal RGB
% A função imapprox reduz o número de cores mapeadas para 10 por canal


% Questão 3

RGB = imread('Laboratorio_Imagens/Laboratorio_3_2.png');
[X,map] = rgb2ind(RGB); % rgb2ind(RGB, 256) não funciona no Octave
figure;
imshow(X,map)
[Y, newmap] = imapprox(X, map, 10); % Reduz para 10 cores por canal
figure;
imshow(Y,newmap)
GR = ind2gray(X,map); % Obtém a imagem X em escala de cinza com o map
RGB2 = ind2rgb(X,map); % Obtém a imagem X com seu mapeamento de cores RGB

figure;
imshow(GR);
figure;
imshow(RGB2);

[X1, map1]= rgb2ind(RGB, 16, 'nodither'); % Obtém imagem com mapeamento de 16 valores por cor
[X2, map2]= rgb2ind(RGB, 16, 'dither'); % O mesmo, porém com dither
% O dither utiliza a mesma limitação de cores, porém distribuindo-as para que
% a média da vizinhança se aproxime da cor original

G1 = dither(GR); % Utiliza o dither na imagem com escala cinza; não presente no Octave
figure;
imshow(RGB);
figure;
imshow(X1,map1);
figure;
imshow(X2,map2);
figure;
imshow(G1);

pause()



% Questão 4
img_3_2 = imread("Laboratorio_Imagens/Laboratorio_3_2.png");
img_3_2_NTSC = rgb2ntsc(img_3_2);
img_3_2_NTSC_lum = img_3_2_NTSC(:,:,1);
img_3_2_NTSC_hum = img_3_2_NTSC(:,:,2);
img_3_2_NTSC_sat = img_3_2_NTSC(:,:,3);
img_3_2_YCbCr = rgb2ycbcr(img_3_2);
img_3_2_HSV = rgb2hsv(img_3_2);

% Não há função para converter RGC para CMY no Octave, faremos manualmente
img_3_2_CMY = img_3_2; 
for a = 1:size(img_3_2_CMY)(1)
    for b = 1:size(img_3_2_CMY)(2)
        for c = 1:size(img_3_2_CMY)(3)
            img_3_2_CMY(a,b,c) = 255 - img_3_2_CMY(a,b,c);
        end
    end
end

figure('Name', 'RGB'), imshow(img_3_2);
figure('Name', 'NTSC'), imshow(img_3_2);
figure('Name', 'Luiminância do NTSC'), imshow(img_3_2_NTSC_lum);
figure('Name', 'Matiz do NTSC'), imshow(img_3_2_NTSC_hum);
figure('Name', 'Saturação do NTSC'), imshow(img_3_2_NTSC_sat);
figure('Name', 'YCbCr'), imshow(img_3_2_YCbCr);
figure('Name', 'HSV'), imshow(img_3_2_HSV);
figure('Name', 'CMY'), imshow(img_3_2_CMY);

pause()

%}

% Questão 5

img_3_2 = imread("Laboratorio_Imagens/Laboratorio_3_2.png");
figure('Name', 'RGB'), imshow(img_3_2);

W = [
    0,1,0;
    1,1,1;
    0,1,0
];

img_3_2_red = img_3_2(:,:,1);
img_3_2_green = img_3_2(:,:,2);
img_3_2_blue = img_3_2(:,:,3);

filtered_red = imfilter(img_3_2_red, W);
filtered_green = imfilter(img_3_2_green, W);
filtered_blue = imfilter(img_3_2_blue, W);
filtered_concat = cat(3, filtered_red, filtered_green, filtered_blue);
figure('Name', 'Filtrada separadamente'), imshow(filtered_concat);

filtered =  imfilter(img_3_2, W);
figure('Name', 'Filtrada sem separação'), imshow(filtered);

filtered_red = medfilt2(img_3_2_red,[15 15]);
filtered_green = medfilt2(img_3_2_green,[15 15]);
filtered_blue = medfilt2(img_3_2_blue,[15 15]);
filtered_concat = cat(3, filtered_red, filtered_green, filtered_blue);
figure('Name', 'Filtrada separadamente com média 15x15'), imshow(filtered_concat);

img_3_2_HSV = rgb2hsv(img_3_2);
figure('Name', 'HSV'), imshow(img_3_2_HSV);

img_3_2_HSV_hum = img_3_2_HSV(:,:,1);
img_3_2_HSV_sat = img_3_2_HSV(:,:,2);
img_3_2_HSV_vib = img_3_2_HSV(:,:,3);

filtered_hum = medfilt2(img_3_2_HSV_hum,[15 15]);
filtered_sat = medfilt2(img_3_2_HSV_sat,[15 15]);
filtered_vib = medfilt2(img_3_2_HSV_vib,[15 15]);
filtered_concat = cat(3, filtered_hum, filtered_sat, filtered_vib);
figure('Name', 'HSV filtrada separadamente com média 15x15'), imshow(filtered_concat);

laplacian = fspecial('laplacian', 0);
filtered_red = imfilter(img_3_2_red, laplacian);
filtered_green = imfilter(img_3_2_green, laplacian);
filtered_blue = imfilter(img_3_2_blue, laplacian);
filtered_concat = cat(3, filtered_red, filtered_green, filtered_blue);
figure('Name', 'Filtrada separadamente com laplaciano'), imshow(filtered_concat);

pause()