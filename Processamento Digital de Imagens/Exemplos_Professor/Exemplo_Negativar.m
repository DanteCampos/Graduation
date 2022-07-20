clear all;
clc;

img_ori = imread('Exemplo_Negativar.jpg');
img_gray = rgb2gray(img_ori);
img_neg = uint8((double(img_gray) - 255) * -1);

figure;
subplot(1,2,1);
imshow(img_gray);
title('Imagem Original');

hold;

subplot(1,2,2);
imshow(img_neg);
title('Imagem Negativada');
