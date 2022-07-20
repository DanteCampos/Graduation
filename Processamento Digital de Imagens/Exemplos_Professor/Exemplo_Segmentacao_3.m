clear all;
clc;

%a=imread('Exemplo_Segmentacao_3A.png');
a=imread('Exemplo_Segmentacao_3B.jpg');
a=imrotate(a,-90);
otsu_a = graythresh(a);
r=a(:,:,1);
otsu_r = graythresh(r);
g=a(:,:,2);
otsu_g = graythresh(g);
b=a(:,:,3);
otsu_b = graythresh(b);

figure;
subplot(2,2,1);
imshow(a);
title('Original');

subplot(2,2,2);
imshow(im2bw(a,0.15));
title('Limiar 1');

subplot(2,2,3);
imshow(im2bw(a,0.55));
title('Limiar 2');

subplot(2,2,4);
imshow(im2bw(a,otsu_a));
title('Otsu');

figure;
subplot(2,2,1);
imshow(r);
title('Canal Red');

subplot(2,2,2);
imshow(im2bw(r,0.15));
title('Limiar 1');

subplot(2,2,3);
imshow(im2bw(r,0.55));
title('Limiar 2');

subplot(2,2,4);
imshow(im2bw(r,otsu_r));
title('Otsu');

figure;
subplot(2,2,1);
imshow(g);
title('Canal Green');

subplot(2,2,2);
imshow(im2bw(g,0.15));
title('Limiar 1');

subplot(2,2,3);
imshow(im2bw(g,0.55));
title('Limiar 2');

subplot(2,2,4);
imshow(im2bw(g,otsu_g));
title('Otsu');

figure;
subplot(2,2,1);
imshow(b);
title('Canal Blue');

subplot(2,2,2);
imshow(im2bw(b,0.15));
title('Limiar 1');

subplot(2,2,3);
imshow(im2bw(b,0.55));
title('Limiar 2');

subplot(2,2,4);
imshow(im2bw(b,otsu_b));
title('Otsu');
