clear all;
clc;

img0 = imread('Exemplo_Frequencia_7.tif');
img = double(imread('Exemplo_Frequencia_7.tif'));

[C,S] = wavedec2(img, 2, 'db1');
C2 = C;
C2(1:64*64) = 0;
img_rec = waverec2(C2, S, 'db1');
subplot(1,2,1);
imshow(img0);
title('Original');

hold;
subplot(1,2,2);
imshow(img_rec,[])
title('Deteccao de Arestas');

img_gray = imread('Exemplo_Frequencia_7.tif');

figure;
subplot(2,2,1);
img_roberts = edge(img_gray,'Roberts');
imshow(img_roberts);
title('Roberts');

hold;

subplot(2,2,2);
img_canny = edge(img_gray,'Canny');
imshow(img_canny);
title('Canny');

hold;
subplot(2,2,3);
img_sobel = edge(img_gray,'Sobel');
imshow(img_sobel);
title('Sobel');

hold;

subplot(2,2,4);
img_prewitt = edge(img_gray,'Prewitt');
imshow(img_prewitt);
title('Prewitt');
