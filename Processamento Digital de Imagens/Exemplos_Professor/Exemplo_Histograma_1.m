clear all;
clc;

%img_ori = imread('Lena.bmp');
img_ori = imread('Exemplo_Histograma_C.png');
img_gray = rgb2gray(img_ori);

figure;
subplot(1,3,1);
imshow(img_ori);
title('Imagem Original');

hold;

subplot(1,3,2);
imshow(img_gray);
title('Escala de Cinza');

hold;

subplot(1,3,3);
plot(imhist(img_gray));
title('Histograma da Imagem em Escala de Cinza');
