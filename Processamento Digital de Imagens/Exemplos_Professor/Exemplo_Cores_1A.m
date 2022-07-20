clear;
clc;

a = imread('Lena.bmp');
r = double(a(10, 10, 1));
g = double(a(10, 10, 2));
b = double(a(10, 10, 3));
Exemplo_Cores_1B(r, g, b);

imshow(a);