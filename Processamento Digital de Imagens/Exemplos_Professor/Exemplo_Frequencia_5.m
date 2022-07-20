clear all;
clc;

%img_ori     = imread('Exemplo_Frequencia_5A.png');
%img_ori     = imread('Exemplo_Frequencia_5B.png');
img_ori     = imread('Exemplo_Frequencia_5C.png');
img_gray    = rgb2gray(img_ori);
img_fourier = fft2(img_gray);

figure;
subplot(2,2,1);
imshow(img_gray);
title('Imagem Tons de Cinza');

hold;
subplot(2,2,2);
imshow(img_fourier);
title('Transformade Discreta de Fourier da Imagem');

hold;
subplot(2,2,3);
imshow(abs(fftshift(img_fourier)),[24 100000]);
title('Espectro de Fourier da Imagem');
