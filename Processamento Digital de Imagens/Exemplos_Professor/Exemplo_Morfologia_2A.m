clear;
clc;

a=rgb2gray(imread('Exemplo_Morfologia_2A.png'));
se=strel('disk', 9);
b=imerode(a,se);
c=imdilate(a,se);

figure;
subplot(1,3,1); imshow(a); title('Original');

hold;
subplot(1,3,2); imshow(b); title('Erode');

hold;
subplot(1,3,3); imshow(c); title('Dilate');
