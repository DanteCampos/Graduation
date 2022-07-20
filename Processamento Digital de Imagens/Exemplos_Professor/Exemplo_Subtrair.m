clear all;
clc;

img_a = imread('Exemplo_Subtrair_2_A.jpg');
img_b = imread('Exemplo_Subtrair_2_B.jpg');
img_c = imsubtract(img_b, img_a);

figure;
subplot(2,2,1);
imshow(img_a);
title('Imagem Original A');

hold;

subplot(2,2,2);
imshow(img_b);
title('Imagem Original B');

hold;
subplot(2,2,4);
imshow(img_c);
title('B - A');
