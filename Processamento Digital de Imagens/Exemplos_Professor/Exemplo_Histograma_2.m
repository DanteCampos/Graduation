clear all;
clc;

imagem=imread('Lena.bmp');

Red = imagem(:,:,1);
Green = imagem(:,:,2);
Blue = imagem(:,:,3);

[yRed, x] = imhist(Red);
[yGreen, x] = imhist(Green);
[yBlue, x] = imhist(Blue);

figure; 
subplot(1,2,1);
imshow(imagem);
title('Imagem Original');

hold
subplot(1,2,2);
plot(x, yRed, 'Red', x, yGreen, 'Green', x, yBlue, 'Blue');
title('Histograma das Cores');             
