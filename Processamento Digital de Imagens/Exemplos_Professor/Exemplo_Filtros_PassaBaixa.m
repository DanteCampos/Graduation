clear all;
clc;

img_ori = imread('Exemplo_Filtros_PassaBaixa.jpg');
img_gray = rgb2gray(img_ori);

figure;
imshow(img_gray);
title('Escala de Cinza');

figure;
filtro = [0 1 0; 1 1 1; 0 1 0];
img_filtrada = filter2(filtro, img_gray);
imshow(img_filtrada);
title('Passa Baixa - Primeiro Filtro');

figure;
filtro = [1 3 1; 3 16 3; 1 3 1];
img_filtrada = filter2(filtro, img_gray);
imshow(img_filtrada);
title('Passa Baixa - Segundo Filtro');

figure;
filtro = [0 -1 0; -1 4 -1; 0 -1 0];
img_filtrada = filter2(filtro, img_gray);
imshow(img_filtrada);
title('Passa Alta');

figure;
filtro = [-1 -1 -1; -1 8 -1; -1 -1 -1];
img_filtrada = filter2(filtro, img_gray);
imshow(img_filtrada);
title('Passa Alta2');
