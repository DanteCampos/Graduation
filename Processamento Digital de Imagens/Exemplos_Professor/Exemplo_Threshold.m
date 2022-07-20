clear all;
clc;

img_ori = imread('Exemplo_Threshold.bmp');

otsu = graythresh(img_ori);
img_bw = im2bw(img_ori,otsu);
display(otsu);

%img_bw = im2bw(img_ori,0.2);

figure;
subplot(1,2,1);
imshow(img_ori);
title('Imagem Original');
hold;

subplot(1,2,2);
imshow(img_bw);
title('Imagem Binarizada com Limiar 100');
