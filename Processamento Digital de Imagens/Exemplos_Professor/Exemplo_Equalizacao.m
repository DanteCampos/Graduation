clear all;
clc;

%img_ori = imread('Exemplo_Equalizacao_B.jpg');
%img_ori = imread('Exemplo_Equalizacao_C.jpg');
img_ori = imread('Exemplo_Alargamento.jpg');
img_gray = rgb2gray(img_ori);
img_equ = histeq(img_gray);
img_equ2 = histeq(img_equ);

figure;
subplot(2,2,1);
imshow(img_gray);
title('Escala de Cinza');

hold;

subplot(2,2,2);
plot(imhist(img_gray));
title('Histograma da Imagem em Escala de Cinza');

hold;

subplot(2,2,3);
imshow(img_equ);
title('Imagem Equalizada');

hold;

subplot(2,2,4);
plot(imhist(img_equ));
title('Histograma da Imagem Equalizada');

figure;

subplot(2,2,1);
imshow(img_equ);
title('IMG_EQU');

hold;

subplot(2,2,2);
imshow(img_equ2);
title('IMG_EQU_2');

hold;

subplot(2,2,3);
plot(imhist(img_equ));
title('HIST - IMG_EQU');

hold;

subplot(2,2,4);
plot(imhist(img_equ2));
title('HIST - IMG_EQU_2');

