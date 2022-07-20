clear all;
clc;

img = imread('Exemplo_Filtros_Gaussiano_A.png');
%img = imread('Exemplo_Filtros_Gaussiano_B.png');
img_gaus = imgaussfilt(img, 2);
subplot(1,2,1);
imshow(img);
title('Imagem Original');
subplot(1,2,2);
imshow(img_gaus);
title('Filtro Gaussiano - sigma = 2');


img2=im2bw(img, 0.7);
img_gaus2=im2bw(img_gaus, 0.7);

figure;
subplot(1,2,1);
imshow(img2);
title('Imagem Original com Threshold 0.7');
subplot(1,2,2);
imshow(img_gaus2);
title('Filtro Gaussiano com Threshold 0.7');

img_mediana = medfilt2(rgb2gray(img));
figure;
imshow(img_mediana);