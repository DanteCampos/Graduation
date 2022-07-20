clear;
clc;

a=rgb2gray(imread('Exemplo_Morfologia_E.png'));

figure;
subplot(2,2,1); imshow(a); title('Original');

a=im2bw(a);
%a = ~a;

hold;
subplot(2,2,2); imshow(a); title('Original');

se=strel('square', 3);

b=imerode(a,se);
b=imdilate(b,se);

b=im2bw(b, 0.2);
hold;
subplot(2,2,3); imshow(b); title('Erode');

c=imdilate(a,se);
hold;
subplot(2,2,4); imshow(c); title('Dilate');
