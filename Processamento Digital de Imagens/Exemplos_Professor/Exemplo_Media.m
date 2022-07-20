clear all;
clc;

img_ori = imread('Exemplo_Media_A.bmp');

figure;
imshow(img_ori);
title('Imagem Original');

figure;
filtro = fspecial('average', [5 5]);
imshow(imfilter(img_ori, filtro));
title('Filtro 5 x 5');

figure;
filtro = fspecial('average', [15 15]);
imshow(imfilter(img_ori, filtro));
title('Filtro 15 x 15');

figure;
filtro = fspecial('average', [25 25]);
imshow(imfilter(img_ori, filtro));
title('Filtro 25 x 25');

figure;
filtro = fspecial('average', [75 75]);
imshow(imfilter(img_ori, filtro));
title('Filtro 75 x 75');
