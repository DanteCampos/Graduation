clear all;
clc;

img = checkerboard;
%img = rgb2gray(imread('Exemplo_Segmentacao_5.jpg'));
%img = rgb2gray(imread('Exemplo_Morfologia_2A.png'));

corners = detectHarrisFeatures(img);

figure;
subplot(1,2,1)
imshow(img);
title('Original');

subplot(1,2,2);
imshow(img);
hold on;
plot(corners.selectStrongest(50));
title('Corners Detectados');
