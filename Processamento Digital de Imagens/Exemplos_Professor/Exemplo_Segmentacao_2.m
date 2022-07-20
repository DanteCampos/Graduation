clear all;
clc;

a=rgb2gray(imread('Exemplo_Segmentacao_2.png'));
b=im2bw(a,0.15);
c=im2bw(a,0.55);
otsu = graythresh(a);
d = im2bw(a,otsu);

figure;
subplot(2,2,1);
imshow(a);
title('Original');

subplot(2,2,2);
imshow(b);
title('Limiar 1');

subplot(2,2,3);
imshow(c);
title('Limiar 2');

subplot(2,2,4);
imshow(d);
title('Otsu');
