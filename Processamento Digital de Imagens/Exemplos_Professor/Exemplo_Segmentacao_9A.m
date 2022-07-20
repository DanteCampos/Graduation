clear;
clc;

img=imread('Exemplo_Segmentacao_9.jpg');
igray=rgb2gray(img);

figure;
subplot(1,2,1);
imshow(img);
title('Original');

segmentada = Exemplo_Segmentacao_9B(igray, 350, 400, 240, 255);

subplot(1,2,2);
imshow(segmentada);
title('Segmentada');

