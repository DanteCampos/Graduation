clear all;
clc;

img=imread('Exemplo_Segmentacao_0.jpg');
igray=rgb2gray(img);

figure;
subplot(2,2,1);
imshow(img);
title('Original');

subplot(2,2,2);
img(143, :) = 0;
imshow(img);
title('Linha Avaliada');

subplot(2,2,3);
plot(igray(143,:));
title('Grafico');
