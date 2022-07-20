clear all;
clc;

img_a = imread('Exemplo_Filtros_Highboost.png');
img_gray = rgb2gray(img_a);
filtro = fspecial('average', [55 55]);
img_suave = imfilter(img_gray, filtro);
img_mascara = imsubtract(img_gray, img_suave);
img_highboost = imadd(img_gray, img_mascara);

figure;
subplot(2,2,1);
imshow(img_a);
title('Imagem Original A');

hold;

subplot(2,2,2);
imshow(img_suave);
title('Imagem Suavizada B');

hold;
subplot(2,2,3);
imshow(img_mascara);
title('Mascara Gerada');

hold;
subplot(2,2,4);
imshow(img_highboost);
title('Mascara Highboost');
