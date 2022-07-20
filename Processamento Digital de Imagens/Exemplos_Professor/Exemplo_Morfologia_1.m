clear all;
clc;

%a=rgb2gray(imread('Exemplo_Morfologia_1A.png'));
%b=rgb2gray(imread('Exemplo_Morfologia_1B.png'));
a=rgb2gray(imread('Exemplo_Morfologia_1C.png'));
b=rgb2gray(imread('Exemplo_Morfologia_1D.png'));
figure; subplot(2,3,1); imshow(a); title('A');
hold; subplot(2,3,2); imshow(b); title('B');
hold; subplot(2,3,3); imshow(~a); title('~A >> Negar');
hold; subplot(2,3,4); imshow(a&b); title('A & B >> Uniao');
hold; subplot(2,3,5); imshow(a|b); title('A | B >> Interseccao');
hold; subplot(2,3,6); imshow(a-b); title('A - B >> Subtracao');

figure;
imshow(imrotate(b,45));
title('Rotacao');

figure;
imshow(imrotate(b,-45));
title('Rotacao');

