clear;
clc;

img_ori = imread('Exemplo_Filtros_Bordas_A.png');
%img_ori = imread('Exemplo_Filtros_Bordas_B.jpg');
%img_ori = imread('Exemplo_Filtros_Bordas_C.png');

img_gray = rgb2gray(img_ori);

figure;
imshow(img_ori);
title('Escala de Cinza');

figure;
subplot(2,2,1);
img_roberts = edge(img_gray,'Roberts');
imshow(img_roberts);
title('Roberts');

hold;
%figure;
subplot(2,2,2);
img_canny = edge(img_gray,'Canny');
imshow(img_canny);
title('Canny');

hold;
%figure;
subplot(2,2,3);
img_sobel = edge(img_gray,'Sobel');
imshow(img_sobel);
title('Sobel');

hold;
%figure;
subplot(2,2,4);
img_prewitt = edge(img_gray,'Prewitt');
imshow(img_prewitt);
title('Prewitt');
